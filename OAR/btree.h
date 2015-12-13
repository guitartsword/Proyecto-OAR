#pragma once
#include "node.h"
#include <string>
#include <fstream>

using namespace std;

class Tree{
    fstream output, input;
	int order;
	int page_count;
	bool up;
public:
    string nombre;
	Node* root;
	Tree(int);
    Tree(int, string);
	void addKey(Node* , Key);
	void Promote(Node* , Key);
	void PrintNodes(Node*);
	bool keyExist(Node*, int key);
	int findKeyRRN(Node* node, int key);
	void saveTree(Node*);
};
