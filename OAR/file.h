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
public:
    File(string, string);
    ~File();
    void addRecord(string);
    void updateFile();
    void deleteRecord(int);
    void saveHeader(vector<Campo>*);
};
