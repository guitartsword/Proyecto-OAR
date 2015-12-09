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

Nodo Promote(Nodo node){
    int promoted=node.getMiddle();
    // 1-Caso --No tiene padre--
    if(node.father==-1){
        Nodo newRoot=Nodo();
        newRoot.father=-1;
        newRoot.addKey(node.getKey(promoted));
        //Split

    }
    return NULL;
}
