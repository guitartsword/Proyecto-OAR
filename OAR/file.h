#pragma once
#include <string>
#include <fstream>
using namespace std;
class File
{
    fstream file;
    string nombre;
public:
    File(string, string);
    void addRecord(string);
    void updateFile();
    void deleteRecord(int);
};
