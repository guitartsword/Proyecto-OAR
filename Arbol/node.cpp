#include "node.h"
#include "key.h"
#include <vector>
#include <algorithm> 
#include <iostream> 

using namespace std;

Node::Node():page(-1){
	this->father= NULL;
}

Node::Node(const Node& other):page(other.page), father(other.father){
    this->children=other.children;
    this->keys=other.keys;
}

void Node::addKey(Key key){
	keys.push_back(key);
	sortKeys();
}

void Node::sortKeys(){
	sort(keys.begin(),keys.end());
}

void Node::sortChildren(){
	sort(children.begin(),children.end());
}

bool Node::hasChildren(){
	if(children.size()>0)
		return true;
	return false;
}

int Node::getKeyCount(){
	return keys.size();
}

int Node::getChildCount(){
	return children.size();
}

Key Node::getMiddle(){
	int middle;
	if(keys.size()%2==0)
		middle=(keys.size()/2)-1;
	else
		middle=(keys.size()/2);
	return keys[middle];
}

Node* Node::Split(){
	int middle;
	if(keys.size()%2==0)
		middle=(keys.size()/2)-1;
	else
		middle=(keys.size()/2);
	vector<Key> derecha(keys.begin() + middle + 1, keys.end());
    vector<Key> izquierda(keys.begin(), keys.begin() + middle);
    Node* left=new Node();
    left->keys=izquierda;
    keys=derecha;
    if(children.size()>0){
    	//sortChildren();
    	vector<Node*> N_derecha(children.begin() + middle + 1, children.end());
    	vector<Node*> N_izquierda(children.begin(), children.begin() + middle + 1);
    	left->children=N_izquierda;
    	children=N_derecha;
    }
    for (int i = 0; i < left->children.size(); i++){
    	left->children[i]->father=left;
    }
    return left;
}

bool operator<(const Node &nodo1, const Node &nodo2){
    if(nodo1.keys[0] < nodo2.keys[0])
        return true;
    else
        return false;
}

void  Node::Print(){
    cout<<"\n-----NODO-----"<<endl;
    cout<<" Page: "<<page<<endl;
	if(father==NULL)
		cout<<" Father: No tiene"<<endl;
	else   
		cout<<" Father: "<<father->page<<endl;
    cout<<" -keys- "<<endl;
    for(int i=0; i< keys.size(); i++){
        cout<<(keys.at(i))<<endl;
    }

    cout<<" -Children- "<<endl;
    if(children.size()>0){
        for(int i=0; i< children.size(); i++){
            cout<<(children[i])->page<<endl;
        }
    }else{
        cout<<" No tiene "<<endl;
    }
}