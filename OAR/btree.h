#pragma once
#include "node.h"

class Tree{
	int order;
	int page_count;
	bool up;
public:
    char* nombre;
	Node* root;
	Tree(int);
	void addKey(Node* , Key);
	void Promote(Node* , Key);
	void PrintNodes(Node*);
	bool keyExist(Node*, int key);
	int findKeyRRN(Node* node, int key);
};
