#include "btree.h"
#include "node.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

Tree::Tree(int order):order(order),page_count(0){
	this->root = new Node();
	up=false;
}

Tree::Tree(int order, string nombre, bool open):order(order),page_count(0),nombre(nombre){
    this->root = new Node();
    up=false;
    nombre+=".TREE";
    if(open){
        cout << "TREE directory: " << nombre << endl;
    	input.open(nombre.c_str(), ios::in);
        output.open(nombre.c_str(), ios::in | ios::out);
        readTree(root);
    }else{
    	output.open(nombre.c_str(), ios::out);
    }   
}

void Tree::addKey(Node* nodo, Key key){
	if(nodo->page==-1){//No existe la raiz
		nodo->page=page_count;
		page_count++;
		nodo->addKey(key);
	}else if(nodo->hasChildren() && !up){//Cuando tenga hijos
		//Buscar el Hijo correcto
		int i;
		for (i = 0; i < nodo->keys.size(); i++){
			if(key.key<nodo->keys[i].key){
				break;
			}
		}
		addKey(nodo->children[i], key);
	}else if(!nodo->hasChildren() || up){//Cuando no tiene hijos
		if(nodo->keys.size()<order-1){//Cuando esta disponible para agregar
			nodo->addKey(key);
		}else{//Cuando no esta disponible para agregar
			Promote(nodo, key);
		}
		up=false;
	}
}


void Tree::Promote(Node* nodo, Key key){
	if(nodo->father==NULL){//Este es el nodo raiz
		nodo->addKey(key);
		Key middle=nodo->getMiddle();
		Node* newRoot= new Node();
		newRoot->keys.push_back(middle);
		newRoot->page=page_count++;
		Node* izquierda=nodo->Split();
		izquierda->page=page_count++;
		izquierda->father=newRoot;
		nodo->father=newRoot;
		newRoot->children.push_back(izquierda);
		newRoot->children.push_back(nodo);
        root = newRoot;
	}else{
        up=true;
        nodo->addKey(key);
		Key middle=nodo->getMiddle();
        Node* izquierda=nodo->Split();
		izquierda->page=page_count++;
        izquierda->father=nodo->father;
        nodo->father->children.push_back(izquierda);
        nodo->father->sortChildren();
        addKey(nodo->father, middle);

	}
}

void Tree::PrintNodes(Node* nodo){
	nodo->Print();
	if(nodo->hasChildren()){
		for (int i = 0; i < nodo->children.size(); ++i){
			PrintNodes(nodo->children[i]);	
		}
	}
}

bool Tree::keyExist(Node* node, int key){
	bool exists=false;
	for (int i = 0; i < node->keys.size(); ++i){
		if(node->keys.at(i).key==key){
			exists=true;
			break;
		}
	}
	if(!exists){
		for(int i = 0; i < node->children.size(); ++i){
			exists=keyExist(node->children.at(i), key);
			if(exists)
				break;
		}
	}
	return exists;
}


int Tree::findKeyRRN(Node* node, int key){
	int RRN=-1;
	for (int i = 0; i < node->keys.size(); ++i){
		if(node->keys.at(i).key==key){
			RRN=node->keys.at(i).rrn;
			break;
		}
	}
	if(RRN==-1){
		for(int i = 0; i < node->children.size(); ++i){
			RRN=findKeyRRN(node->children.at(i), key);
			if(RRN!=-1)
				break;
		}
	}
	return RRN;

}

void Tree::saveTree(Node* node, bool start){
    char* buffer;//4bytes + 4bytes de cantidad+(8*(order-1))+(4*order)
    //Se escribe el numero de pagina
    if(start)
        output.seekp(0,output.beg);
    int page = node->page;
    output.write(reinterpret_cast<char*>(&page),4);
    //Se escriben 4 bytes de cantidad de keys
    int keySize = node->keys.size();
    output.write(reinterpret_cast<char*>(&keySize),4);
    //Se escriben las llaves

    for (int i = 0; i < node->keys.size(); i++){
        output.write(reinterpret_cast<char*>(&node->keys[i].key), 4);
        output.write(reinterpret_cast<char*>(&node->keys[i].rrn), 4);
    }
    //Se escribe el espacio de las otras llaves
    buffer = new char[8*(order - 1 - node->keys.size())];
    for(int i = 0; i < 8*(order - 1 - node->keys.size()); i++){
    	buffer[0] = 0;
    }
    output.write(buffer, 8*(order - 1 - node->keys.size()));
    //Se escribe la pagina de los hijos
    int childSize = node->children.size();
    output.write(reinterpret_cast<char*>(&(childSize)),4);
    for(int i = 0; i < node->children.size(); i++){
    	int childPage=node->children[i]->page;
        output.write(reinterpret_cast<char*>(&childPage),4);
    }
    delete buffer;
    //ESCRIBE EL ESPACIO DE LOS HIJUEPUETAS
    buffer = new char[4*(order - node->children.size())];
    for(int i = 0; i < 4*(order - node->children.size()); i++){
    	buffer[0] = 0;
    }
    output.write(buffer, 4*(order - node->children.size()));
    delete buffer;
    node->Print();
    for(int i = 0; i < node->children.size(); i++)
        saveTree(node->children.at(i),false);
    output.flush();
}

void Tree::readTree(Node* nodo, bool start){
	if(start)
		iterator = 0;

	int page = 0;
	int offset = (4 + 4 + 4 + 8*(order-1) + 4*(order)) * iterator;
	cout << "offset " << offset << endl;
	input.seekg(offset, input.beg);
	input.read(reinterpret_cast<char*>(&page),4);
	cout << "Page " << page << endl;
	int keySize = 0;
	//input.seekg(4, input.beg);
	input.read(reinterpret_cast<char*>(&keySize),4);
	cout << "keySize " << keySize << endl;
	vector<Key> keys;
	for(int i = 0; i < keySize; i++){
		int key=0, rrn=0;
		//input.seekg(8*(i+1), input.beg);
		input.read(reinterpret_cast<char*>(&(key)),4);
		//input.seekg(8*(i+1) + 4, input.beg);
		input.read(reinterpret_cast<char*>(&(rrn)),4);
		Key temp(key, rrn);
		keys.push_back(temp);
		cout << "KEY " << temp << endl;
	}
	input.seekg((8*(order)) + offset, input.beg);
	cout << "read child size in offset = " << input.tellg() << endl;
	vector<Node*> children;
	int childSize = 0;
	input.read(reinterpret_cast<char*>(&childSize), 4);
	cout << "childSize " << childSize << endl;
	for(int i = 0; i < childSize; i++){
		int childPage=0;
		input.read(reinterpret_cast<char*>(&childPage),4);
		Node* temp = new Node();
		temp->page = childPage;
		temp->father = nodo;
		nodo->children.push_back(temp);
		cout << "childPage " << childPage << endl;
		cout << "tempchildPage " << temp->page << endl;
		cout << "lastchildNOdopage " << nodo->children.at(nodo->children.size()-1)->page << endl;
	}
	if(nodo->father == NULL)
		nodo->page = page;
	nodo->keys = keys;
	for(int i = 0; i < nodo->children.size(); i++){
		iterator++;
		cout << "iterator" << iterator << endl;
        readTree(nodo->children.at(i), false);
	}
}
