#pragma once
#include <iostream>
using namespace std;
class Key{
public:
	int key;
	int rrn;
	Key(int, int);
	friend ostream& operator<<(ostream&, const Key&);
};
bool operator<(const Key &key1, const Key &key2);