#pragma once
#include "key.h"
#include <vector>

using namespace std;

class Nodo{
    vector<Key*> keys;
    vector<int> children;
public:
    int page;
    int father;
    Nodo();
    Nodo(int page);
    void addKey(Key*);
    void addChild(int);
    bool isAvailableToAdd(int order);
    bool hasChildren();
    Key* getMiddle();
    Key* getKey(int pos);
    void deleteKey(int pos);
    Nodo Split();
};
