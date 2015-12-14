#pragma once
#include "node.h"
#include <string>
#include <fstream>

using namespace std;

class Tree{

	int order;
	int page_count;
	bool up;
	int iterator;
public:
    fstream output, input;
    string nombre;
	Node* root;
	Tree(int);
    Tree(int, string, bool);
	void addKey(Node* , Key);
	void Promote(Node* , Key);
	void PrintNodes(Node*);
	bool keyExist(Node*, int key);
	int findKeyRRN(Node* node, int key);
    void saveTree(Node*,bool=1);
	void readTree(Node*,bool=1);
    void deleteKey(Node* nodo, Key key);
    Node* findKeyNode(Node* node, int key);
};
