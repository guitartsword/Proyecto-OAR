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
    if(keys.size()>0)
        sort(keys.begin(),keys.end());
}

void Node::sortChildren(){
    Node* keys[children.size()];
    int cont=0;
    for (int i = 0; i < children.size(); i++){
        for (int j = 0; j < children.size(); j++){
            if(children.at(i)->keys.at(0).key < children.at(j)->keys.at(0).key){
                cont++;
            }
        }
        keys[cont]=children.at(i);
        cont=0;
    }

    vector<Node*> Children;
    for (int i = children.size()-1; i >= 0; i--){
        Children.push_back(keys[i]);
    }
    children=Children;
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
    cerr << "Middle = " << middle << endl;
    for(int i = 0; i < derecha.size(); i++){
        cerr << derecha[i] << ",";
    }
    cerr << endl;
    for(int i = 0; i < izquierda.size(); i++){
        cerr << izquierda[i] << ",";
    }
    cerr << endl;
    Node* left=new Node();
    left->keys=izquierda;
    keys=derecha;

    cout << "CHILDREN SIZE = " << children.size() << endl;
    if(children.size()>0){
        if(children.size()%2==0)
            middle=(children.size()/2)-1;
        else
            middle=(children.size()/2);
        vector<Node*> N_derecha;
        vector<Node*> N_izquierda;
        for(int i = 0; i < children.size(); i++){
            cerr << "CHILDREN" << endl;
            cerr << children.at(i) << endl;
            cerr << "CHILDREN" << endl;
        }
        for(int i = 0; i < middle + 1; i++){
            N_izquierda.push_back(children.at(i));
        }
        for(int i = middle + 1; i < children.size(); i++){
            N_derecha.push_back(children.at(i));
        }
        left->children=N_izquierda;
        children=N_derecha;
    }
    for (int i = 0; i < left->children.size(); i++){
        left->children[i]->father=left;
    }
    return left;
}

bool operator<(const Node &nodo1, const Node &nodo2){
    cout << "LAKSDJASDJLKASDLKLKJSDALKJASDLKJASDLJKLAKJDSLKJADSLKJASDLKLKJWSDA" << endl;
    if(nodo1.keys.at(0).key < nodo2.keys.at(0).key)
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
