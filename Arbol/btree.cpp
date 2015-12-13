#include "btree.h"
#include "node.h"

Tree::Tree(int order):order(order),page_count(0){
	this->root = new Node();
	up=false;
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
		addKey(nodo->father, middle);
		Node* izquierda=nodo->Split();
		izquierda->page=page_count++;
        //
        izquierda->father=nodo->father;
        //EDIT
        nodo->father->children.push_back(izquierda);
        nodo->father->sortChildren();
        //END EDIT
        izquierda->Print();
		nodo->Print();

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
