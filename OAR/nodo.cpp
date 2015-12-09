#include "nodo.h"
#include "key.h"
#include <vector>
#include <cmath>

using namespace std;

Nodo::Nodo():page(-1),father(-1){}

Nodo::Nodo(int page):page(page){}

void  Nodo::addKey(Key* key){
    keys.push_back(key);
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

int Nodo::getMiddle(){
    int middle=round(keys.size()/2);
    return middle;
}

Key* Nodo::getKey(int pos){
    return keys.at(pos);
}
void Nodo::deleteKey(int pos){
    keys.erase(keys.begin()+pos);
}
