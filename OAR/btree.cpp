#include "btree.h"
#include "nodo.h"
#include "key.h"
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

BTree::BTree():order(0),up(false){
    root=Nodo();
}

BTree::BTree(int order):order(order),up(false){
    root=Nodo();
    cout<<"Se creo un arbol de orden: "<<order<<endl;
}

void  BTree::Print(Nodo node){
    node.Print();
}


void  BTree::PrintNodes(){
    for (int i = 0; i < nodos.size(); ++i)
    {
        nodos.at(i).Print();
    }
}

Nodo*  BTree::getNodo(int page){
    Nodo* temp;
    for (int i = 0; i < nodos.size(); ++i){
        if(nodos.at(i).page==page){
            temp=&(nodos.at(i));
        }
    }
    return temp;
}

void BTree::addKey(Nodo &node, Key key){
    // 1-Caso --Raiz no existe--
    if(node.page==-1){
        node.page=0;
        pages.push_back(0);
        node.father=-1;
        node.addKey(key);
        nodos.push_back(node);

    }else if(node.hasChildren() && !up){// 2-Caso --Nodo existe pero tiene hijos--
        int pos=0;
        Nodo* tempo=findNode(node.page);
        for(int i=0; i<tempo->getKeysCount(); i++){
            if(key.key>tempo->getKey(i).key){
                pos=i;
            }
        }
        Nodo* temp=getNodo(node.getChild(pos));
        addKey(*temp, key);
    }else if(!node.hasChildren()){// 2-Caso --Nodo existe pero no tiene hijos--
        if(node.isAvailableToAdd(order)){// 2.1-Caso --Esta disponible para agregar--
            node.addKey(key);
        }else{// 2.2-Caso --No esta disponible para agregar--
            Promote(node, key);
        }

    }else if(up){
        if(node.isAvailableToAdd(order)){//Cuando se manda el promote desde abajo
            node.addKey(key);
        }else{
            Promote(node,key);
        }
        up=false;
    }
}

void  BTree::Promote(Nodo &node, Key key){
    // 1-Caso --Cuando es raiz--
    if(node.father==-1){
        //Crear el nuevo nodo con la llave anterior
        node.addKey(key);
        Key temp=node.getMiddle();
        Nodo NewRoot= Nodo();
        NewRoot.father=-1;
        NewRoot.addKey(temp);
        //Split
        Nodo newNode= node.Split();

        //Asignarle una nueva pagina y guardarla
        int newPageNum=pages.at(pages.size()-1)+1;
        NewRoot.page= newPageNum;
        pages.push_back(newPageNum);
        int newPageNum_Child=pages.at(pages.size()-1)+1;
        newNode.page=newPageNum_Child;
        pages.push_back(newPageNum_Child);

        //Asignarle el padre 
        node.father=newPageNum;
        newNode.father=newPageNum;
        NewRoot.addChild(newNode.page);
        NewRoot.addChild(node.page);


        //HIJOS
        if(node.hasChildren()){
            Nodo* x;
            int middle=round(node.getChildrenCount()/2);
            for (int i = 0; i < middle; ++i){
                newNode.addChild(node.getChild(i));
                x=findNode(node.getChild(i));
                x->father=newNode.page;
            }
            for (int i = 0; i < middle; ++i){
                node.deleteChild();
            }
        }

        //Se insertan el vector de nodos
        Nodo newNode2(node);
        
        nodos.push_back(NewRoot);
        nodos.push_back(newNode);
        nodos.push_back(newNode2);
        deleteNode(node.page);

        root=NewRoot;

    }else{// 1-Caso --Cuando no es raiz--
        up=true;
        node.addKey(key);
        Key temp=node.getMiddle();
        Nodo* tempNode=getNodo(node.father);
        addKey(*tempNode, temp);
        Nodo* tempo=findNode(node.page);
        Nodo newNode= tempo->Split();

        int newPageNum=pages.at(pages.size()-1)+1;
        newNode.page=newPageNum;
        tempNode->addChild(newPageNum);

        if(nodos.at(nodos.size()-1).getChildrenCount()>0){
            nodos.at(nodos.size()-1).addChild(newPageNum);
            newNode.father=nodos.at(nodos.size()-1).page;
        }else{
            newNode.father=tempNode->page;
        }
        pages.push_back(newPageNum);
        nodos.push_back(newNode);
        tempNode=findNode(tempNode->page);
        //Ordenar Hijos dependiendo del key
        if(tempNode->hasChildren()){
            vector<int> Children;
            int keys[tempNode->getChildrenCount()];
            int x, y, cont=0;
            for (int i = 0; i < tempNode->getChildrenCount(); i++){
                for (int j = 0; j < tempNode->getChildrenCount(); j++){
                    if(nodos.size()>0 && tempNode->getKeysCount()>0){
                        x = findNode(tempNode->getChild(i))->getKey(0).key;
                        y = findNode(tempNode->getChild(j))->getKey(0).key;
                        if(x<y){
                            cont++;
                        }
                    }
                }
                keys[cont]=tempNode->getChild(i);
                cont=0;
            }
            for (int i = tempNode->getChildrenCount()-1; i >= 0; i--){
                Children.push_back(keys[i]);
            }
            tempNode->setChildren(Children);
        }
        
        if(tempo->hasChildren()){
            int middle=round(tempo->getChildrenCount()/2);
            Nodo* x;
            for (int i = 0; i < middle; ++i){
                newNode.addChild(tempo->getChild(i));
                x=findNode(tempo->getChild(i));
                x->father=newPageNum;
            }
            for (int i = 0; i < middle; ++i){
                tempo->deleteChild();
            }
        }
    }

}

void BTree::deleteNode(int page){
    int i;
    for ( i= 0; i < nodos.size(); ++i){
        if(nodos.at(i).page==page){
            break;
        }
    }
    nodos.erase(nodos.begin()+i);
}

Nodo* BTree::findNode(int page){
    int i;
    for ( i= 0; i < nodos.size(); ++i){
        if(nodos.at(i).page==page){
            break;
        }
    }
    return &nodos.at(i);
}