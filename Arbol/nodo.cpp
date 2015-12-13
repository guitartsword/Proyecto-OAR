#include "nodo.h"
#include "key.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm> 

using namespace std;

Nodo::Nodo():page(-1),father(-1){}

Nodo::Nodo(int page):page(page){}

Nodo::Nodo(const Nodo& other):page(other.page), father(other.father){
    this->children=other.children;
    this->keys=other.keys;
}

void  Nodo::Print(){
    cout<<"\n-----NODO-----"<<endl;
    cout<<" Page: "<<page<<endl;
    cout<<" Father: "<<father<<endl;
    cout<<" -keys- "<<endl;
    for(int i=0; i< keys.size(); i++){
        cout<<(keys.at(i))<<endl;
    }

    cout<<" -Children- "<<endl;
    if(children.size()>0){
        for(int i=0; i< children.size(); i++){
            cout<<(children.at(i))<<endl;
        }
    }else{
        cout<<" No tiene "<<endl;
    }
}

void Nodo::sortKeys(){
    sort(keys.begin(),keys.end());
}

void  Nodo::addKey(Key key){
    keys.push_back(key);
    sortKeys();
}

void  Nodo::addChild(int child){
    children.push_back(child);
}

bool Nodo::isAvailableToAdd(int order){
    if(keys.size()<(order-1))
        return true;
    else
        return false;
}

bool Nodo::hasChildren(){
    if(children.size()>0)
        return true;
    else
        return false;
}
Key Nodo::getMiddle(){
    //Saca la llave que sera promovida
    int middle=round(keys.size()/2)-1;
    Key temp=keys.at(middle);
    return temp;
}

Key Nodo::getKey(int pos){
    return keys.at(pos);
}

void Nodo::deleteKey(int pos){
    keys.erase(keys.begin()+pos);
}

Nodo Nodo::Split(){
    int middle=round(keys.size()/2)-1;
    Nodo newNode=Nodo();
    for(int i=0; i<middle;i++){
        newNode.addKey(keys.at(i));
    }
    for(int i=0; i<middle+1;i++){
        keys.erase(keys.begin());
    }
    return newNode;
}

int Nodo::getKeysCount(){
    return keys.size();
}

int Nodo::getChildrenCount(){
    return children.size();
}

int Nodo::getChild(int pos){
    return children.at(pos);
}

void Nodo::deleteChild(){
    children.erase(children.begin()+0);
}

void Nodo::deleteLastChild(){
    children.erase(children.begin()+children.size()-1);
}

void Nodo::setChildren(vector<int> children){
    this->children=children;

}