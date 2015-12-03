#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "campo.h"

using namespace std;
class File
{
    string nombre;
    fstream file;
    int header_size;
    bool write;
public:
    File(string, string, bool);
    ~File();
    void addRecord(string);
    void updateFile();
    void deleteRecord(int);
    void saveHeader(vector<Campo>*);
    void calcHeaderSize();
};
