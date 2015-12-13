#include "key.h"
#include <iostream>
#include <sstream>
using namespace std;

Key::Key(int key, int rrn):key(key),rrn(rrn){}

ostream& operator<<(ostream& output, const Key& key){
	output << key.key << " " << key.rrn;
	return output;
}

bool operator<(const Key &key1, const Key &key2){
    if(key1.key < key2.key)
        return true;
    else
        return false;
}