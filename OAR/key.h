#pragma once
#include <iostream>
using namespace std;

class Key{
    int rrn;
public:
	int key;
    Key(int, int);
    string toString()const;
    friend ostream& operator<<(ostream&, const Key&);
};
bool operator<(const Key &key1, const Key &key2);