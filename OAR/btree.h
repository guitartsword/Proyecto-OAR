#pragma once
#include "node.h"

class Tree{
	int order;
	int page_count;
	bool up;
public:
	Node* root;
	Tree(int);
	void addKey(Node* , Key);
	void Promote(Node* , Key);
	void PrintNodes(Node*);
};