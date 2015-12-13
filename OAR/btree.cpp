#include "btree.h"
#include "node.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

Tree::Tree(int order):order(order),page_count(0){
	this->root = new Node();
	up=false;
}

Tree::Tree(int order, string nombre):order(order),page_count(0),nombre(nombre){
    this->root = new Node();
    up=false;
    nombre+=".TREE";
    output.open(nombre.c_str(), ios::out);
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

void Tree::saveTree(Node* node){
	char* buffer;//3+3+(6*(order-1))+(3*order)
	//Se escribe el numero de pagina
	buffer = new char[3];
	buffer[0]=node->page;
	output.write(buffer,3);
	//Se escribe la cantidad de keys que tiene
	buffer = new char[3];
    buffer[0]=node->keys.size();
    output.write(buffer, 3);
    //Se escriben las llaves
    for (int i = 0; i < node->keys.size(); i++){
    	buffer = new char[3];
    	buffer[0]=node->keys[i].key;
    	output.write(buffer, 3);

    	buffer = new char[3];
    	buffer[0]=node->keys[i].rrn;
    	output.write(buffer, 3);
    }
    //Se escribe el numero de hijos
    for(int i = 0; i < node->children.size(); i++){
    	buffer = new char[3];
        buffer[0]=node->children[i]->page;
    	output.write(buffer, 3);
    }
}






