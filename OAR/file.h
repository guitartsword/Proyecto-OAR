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
    vector<Campo> campos;
    int recordSize();
    void updateAvail(int);
    long unsigned int searchIndex(int);//Retorna el offset del indice del registro
public:
    File(string, string, bool);
    ~File();
    void addRecord(string, int);
    void updateFile();
    void deleteRecord(int);
    void saveHeader(vector<Campo>&);
    void reCalcHeaderSize();
    void appendRecord(string);
    unsigned int getRRN();
    bool isOpen()const;
    int recordCount();
    char** getRecord(int, bool RRN);//retorna los datos del registro
    vector<Campo>& getCampos();
};
