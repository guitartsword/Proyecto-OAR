#include "btree.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	Tree arbol(6);
	Key temp(10,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(32,0);
	arbol.addKey(arbol.root, temp);

	temp= Key(56,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(1,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(100,0);
	arbol.addKey(arbol.root, temp);	

	temp=Key(50,0);
	arbol.addKey(arbol.root, temp);	

	temp=Key(60,0);
	arbol.addKey(arbol.root, temp);	

	temp=Key(5,0);
	arbol.addKey(arbol.root, temp);	

	temp=Key(70,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(6,0);
	arbol.addKey(arbol.root, temp);	
    
	temp=Key(77,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(24,0);
	arbol.addKey(arbol.root, temp);	

	temp=Key(25,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(27,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(26,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(28,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(30,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(31,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(29,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(61,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(62,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(63,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(105,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(123,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(9,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(7,0);
	arbol.addKey(arbol.root, temp);

	temp=Key(8,0);
	arbol.addKey(arbol.root, temp);

	cout<<endl;
	//arbol.PrintNodes(arbol.root);
	return 0;
}