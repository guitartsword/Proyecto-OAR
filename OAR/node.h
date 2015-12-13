#pragma once
#include "key.h"
#include <vector>

using namespace std;

class Node{
public:
	vector<Key> keys;
	vector<Node*> children;
	int page;
	Node* father;
	Node();
	Node(const Node&);
	void addKey(Key);
	void sortKeys();
	void sortChildren();
	bool hasChildren();
	int getKeyCount();
	int getChildCount();
	Key getMiddle();
	Node* Split();
	void  Print();
	friend ofstream& operator<<(ofstream&, const Node&);
};
bool operator<(const Node &nodo1, const Node &nodo2);