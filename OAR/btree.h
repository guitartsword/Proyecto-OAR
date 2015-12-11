#pragma once
#include "nodo.h"
#include "key.h"
#include <vector>

using namespace std;

class BTree{
    int order;
    Nodo root;
    vector<int> pages;
public:
    BTree();
    BTree(int);
    void addKey(Nodo, Key*);
    void delKey(int);
    Nodo Promote(Nodo node, Key* key);
};
