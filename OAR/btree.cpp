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
    nombre = nombre.substr(0,nombre.size()-4);
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

Node* Tree::findKeyNode(Node* node, int key){
    Node* temp = new Node();
    for (int i = 0; i < node->keys.size(); ++i){
        if(node->keys.at(i).key==key){
            temp=node;
            break;
        }
    }
    if(temp->page==-1){
        for(int i = 0; i < node->children.size(); ++i){
            temp=findKeyNode(node->children.at(i), key);
            if(temp->page!=-1)
                break;
        }
    }
    return temp;
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
    for(int i = 0; i < node->children.size(); i++)
        saveTree(node->children.at(i),false);
    output.flush();
}

void Tree::readTree(Node* nodo, bool start){
	if(start)
		iterator = 0;

	int page = 0;
    int offset = (4+12*order) * iterator;
	input.seekg(offset, input.beg);
    input.read(reinterpret_cast<char*>(&page),4);
	int keySize = 0;
	//input.seekg(4, input.beg);
    input.read(reinterpret_cast<char*>(&keySize),4);
	vector<Key> keys;
	for(int i = 0; i < keySize; i++){
		int key=0, rrn=0;
		//input.seekg(8*(i+1), input.beg);
		input.read(reinterpret_cast<char*>(&(key)),4);
		//input.seekg(8*(i+1) + 4, input.beg);
		input.read(reinterpret_cast<char*>(&(rrn)),4);
		Key temp(key, rrn);
        keys.push_back(temp);
	}
    input.seekg((8*(order)) + offset, input.beg);
	vector<Node*> children;
	int childSize = 0;
    input.read(reinterpret_cast<char*>(&childSize), 4);
	for(int i = 0; i < childSize; i++){
		int childPage=0;
		input.read(reinterpret_cast<char*>(&childPage),4);
		Node* temp = new Node();
		temp->page = childPage;
		temp->father = nodo;
        nodo->children.push_back(temp);
	}
	if(nodo->father == NULL)
		nodo->page = page;
	nodo->keys = keys;
	for(int i = 0; i < nodo->children.size(); i++){
        iterator++;
        readTree(nodo->children.at(i), false);
	}
}

void Tree::deleteKey(Node* nodo, Key key){//El nodo que contiene la llave
    int posicion=0;
    cout << "antes de la posicion";
    for(posicion=0; posicion < nodo->keys.size();posicion++){
        if(nodo->keys.at(posicion).key==key.key){
            break;
        }
    }
    if(!nodo->hasChildren() || up){//Si no tiene hijos
        cout << "Si no tiene hijos" << endl;
        nodo->deleteKey(posicion);
        if(nodo->keys.size()>((order/2)-1)){//Se mira si esta en underflow
            cout << "Se mira si esta en underflow, borrado directo" << endl;
            //Borrado directo
        }else{//Pedir Presatado o Merge(mero Vergeo)
            cout << "Pedir Presatado o Merge(mero Vergeo)"<<endl;

            underflow(nodo, key, posicion);

        }
        up = false;
    }else{//Sucesor inmediato luego borrar de la hoja
        Node* sucesor;
        sucesor = nodo->children.at(0);
        while(sucesor->hasChildren())
            sucesor = sucesor->children.at(sucesor->children.size()-1);
        Key switchKey = nodo->keys.at(posicion);
        //Se efectua el switch
        nodo->keys.at(posicion) = sucesor->keys.at(sucesor->keys.size()-1);
        sucesor->keys.at(sucesor->keys.size()-1) = switchKey;
        deleteKey(sucesor, key);
    }
}

void Tree::underflow(Node* nodo, Key key, int posicion/*Posicion de la key en el nodo actual*/){
    //Se agarra la posicion del nodo actual
    cout << "DENTRO DEL UNDERFLOW" << endl;
    if(nodo->father != NULL){
        cout << "TENGO PAPI :)" << endl;
        int pos_nodo=0;//Posicion del nodo actual en los hijos del padre del nodo actual
        for(pos_nodo=0; nodo->father->children.size();pos_nodo++){
            if(nodo->father->children.at(pos_nodo)->page==nodo->page){
                break;
            }
        }
        bool pedirPrestado = false;
        if(pos_nodo-1>=0){//Borrow Hijo izquierdo
            cout << "Borrow Hijo izquierdo" << endl;
            Node* brother=nodo->father->children.at(pos_nodo-1);
            if(brother->AvailabletoBorrow(order)){
                cout << "Si puede prestar" << endl;
                Key keyFather=nodo->father->keys.at(pos_nodo-1);
                nodo->addKey(keyFather);
                nodo->father->deleteKey(pos_nodo-1);

                Key upFather=brother->keys.at(brother->keys.size()-1);
                nodo->father->addKey(upFather);
                brother->deleteKey(brother->keys.size()-1);
                if(brother->hasChildren()){
                    nodo->children.push_back(brother->children.at(brother->getChildCount()-1));
                    brother->children.at(brother->getChildCount()-1)->father = nodo;
                    brother->deleteChildren(brother->getChildCount()-1);
                    nodo->sortChildren();
                }
                pedirPrestado = true;
            }
        }
        if(pos_nodo+1<nodo->father->children.size() && !pedirPrestado){//Borrow Hijo derecho
            Node* brother=nodo->father->children.at(pos_nodo+1);
            cout << "Borrow Hijo derecho" << endl;
            if(nodo->father->children.at(pos_nodo+1)->AvailabletoBorrow(order)){
                cout << "Si puede prestar" << endl;
                Key keyFather=nodo->father->keys.at(pos_nodo);
                nodo->addKey(keyFather);
                nodo->father->deleteKey(pos_nodo);

                Key upFather=brother->keys.at(0);
                nodo->father->addKey(upFather);
                brother->deleteKey(0);
                if(brother->hasChildren()){
                    nodo->children.push_back(brother->children.at(0));
                    brother->children.at(0)->father = nodo;
                    brother->deleteChildren(0);
                    nodo->sortChildren();
                }
            }else{
                //MERGE
                Merge(nodo, pos_nodo);
            }
        }
    }else{
        cout << "No tengo papi :c" << endl;
       if(nodo->keys.empty()){
           root = nodo->children.at(0);
           root->father = NULL;
       }
    }
}
void Tree::Merge(Node* nodo, int pos_nodo){
    cout << "Pues hago merge" << endl;
    if(pos_nodo-1>=0){// CON el Hijo izquierdo
        cout << "CON el Hijo izquierdo" << endl;
        Node* brother=nodo->father->children.at(pos_nodo-1);
        for(int i = 0; i < nodo->keys.size(); i++){
            brother->addKey(nodo->keys.at(i));
        }
        for(int i = 0; i < nodo->children.size(); i++){
            nodo->children.at(i)->father = brother;
            brother->children.push_back(nodo->children.at(i));
        }
        if(brother->children.size()>0)
            brother->sortChildren();
        nodo->father->deleteChildren(pos_nodo);
        brother->addKey(nodo->father->keys.at(pos_nodo-1));
        up = true; //QUE NO BUSQUE LOS HIJOS
        deleteKey(nodo->father,nodo->father->keys.at(pos_nodo-1));
    }else if(pos_nodo+1 < nodo->father->children.size()){// CON el Hijo derecho cuando no se puede con el izquierdo
        cout << "CON el Hijo derecho cuando no se puede con el izquierdo" << endl;
        Node* brother=nodo->father->children.at(pos_nodo+1);
        for(int i = 0; i < nodo->keys.size(); i++){
            brother->addKey(nodo->keys.at(i));
        }
        for(int i = 0; i < nodo->children.size(); i++){
            nodo->children.at(i)->father = brother;
            brother->children.push_back(nodo->children.at(i));
        }
        if(brother->children.size()>0)
            brother->sortChildren();
        nodo->father->deleteChildren(pos_nodo);
        brother->addKey(nodo->father->keys.at(pos_nodo));
        up = true; //QUE NO BUSQUE LOS HIJOS
        deleteKey(nodo->father,nodo->father->keys.at(pos_nodo));
    }
}
