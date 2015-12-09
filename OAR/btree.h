#pragma once
#include "nodo.h"
#include "key.h"

using namespace std;

class BTree{
    int order;
    Nodo root;
public:
    BTree();
    BTree(int);
    void addKey(Nodo, Key*);
    void delKey(int);
};
