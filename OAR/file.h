#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "campo.h"

using namespace std;
class File
{
    string nombre;
    fstream output, input;
    int header_size;
    bool write;
    string filepath;
    int recordSize();
public:
    File(string, string, bool);
    ~File();
    void addRecord(string, int);
    void updateFile();
    void deleteRecord(int);
    void saveHeader(vector<Campo>*);
    void reCalcHeaderSize();
    void appendRecord(string);
    int getRRN();
    int LookforAvail();
    bool isOpen()const;
    int recordCount();
};
