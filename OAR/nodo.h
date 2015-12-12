#pragma once
#include "key.h"
#include <vector>

using namespace std;

class Nodo{
    vector<Key> keys;
    vector<int> children;
public:
    int page;
    int father;
    Nodo();
    Nodo(int page);
    Nodo(const Nodo&);
    void Print();
    void sortKeys();
    int getKeysCount();
    int getChildrenCount();
    void addKey(Key);
    void addChild(int);
    bool isAvailableToAdd(int order);
    bool hasChildren();
    Key getMiddle();
    Key getKey(int pos);
    void deleteKey(int pos);
    Nodo Split();
    int getChild(int pos);
    void deleteChild();
    void deleteLastChild();
    void setChildren(vector<int> children);
};
