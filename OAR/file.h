#pragma once
#include <fstream>
#include <string>
using namespace std;
class File
{
    fstream File;
    string nombre;
public:
    File(fstream, string);
    void addRecord(string);
    void updateFile();
    void deleteRecord(int);
};
