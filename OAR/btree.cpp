#include "btree.h"
#include "nodo.h"
#include "key.h"
#include <cstdio>

using namespace std;

BTree::BTree():order(0){
    root=Nodo();
}

BTree::BTree(int order):order(order){
    root=Nodo();
}

void BTree::addKey(Nodo node, Key* key){
    // 1-Caso --Raiz no existe--
    if(node.page==-1){
        node.page=0;
        pages.push_back(0);
        node.father=-1;
        node.addKey(key);
    }else if(!node.hasChildren()){// 2-Caso --Raiz existe pero no tiene hijos--
        if(node.isAvailableToAdd(order)){// 2.1-Caso --Esta disponible para agregar--
            node.addKey(key);
        }else{// 2.2-Caso --No esta disponible para agregar--
            //Promote

            //Split

            //Agregar

        }

    }else{// 3-Caso --Raiz existe pero tiene hijos--
        //Recursividad

    }
}

Nodo  BTree::Promote(Nodo node, Key* key){
    // 1-Caso --No tiene padre--
    if(node.father==-1){
        //Crear el nuevo nodo con la llave anterior
        node.addKey(key);
        Key* temp=node.getMiddle();
        Nodo NewRoot= Nodo();
        NewRoot.father=-1;

        //Split
        Nodo newNode= node.Split();

        //Asignarle una nueva pagina y guardarla
        int newPageNum=pages.at(pages.size()-1)+1;
        NewRoot.page= newPageNum;
        pages.push_back(newPageNum);
        int newPageNum_Child=pages.at(pages.size()-1)+1;
        newNode.page=newPageNum_Child;
        pages.push_back(newPageNum_Child);

        //Asignarle el padre y los hijos
        node.father=newPageNum;
        newNode.father=newPageNum;
        NewRoot.addChild(node.page);
        NewRoot.addChild(newNode.page);
        NewRoot.addKey(temp);

        delete temp;
    }
    return NULL;
}
