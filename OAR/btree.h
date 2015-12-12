#pragma once
#include "nodo.h"
#include "key.h"
#include <vector>

using namespace std;

class BTree{
    int order;
    vector<int> pages;
    vector<Nodo> nodos;
    bool up;
public:
	Nodo root;
    BTree();
    BTree(int);
    void Print(Nodo node);
    void PrintNodes();
    void addKey(Nodo&, Key);
    void delKey(int);
    void Promote(Nodo& node, Key key);
    Nodo* getNodo(int page);
    void deleteNode(int page);
    Nodo* findNode(int page);
    void sortChildren(Nodo& node);
};
