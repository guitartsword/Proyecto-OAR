#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "campo.h"
#include "btree.h"

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
    Tree arbol;
public:
    File(string, string, bool);
    ~File();
    void addRecord(int,string, int);
    void updateFile();
    void deleteRecord(unsigned int);
    void saveHeader(vector<Campo>&);
    void reCalcHeaderSize();
    void appendRecord(int, string);
    unsigned int getRRN();
    bool isOpen()const;
    int recordCount();
    char** getRecord(int ID, bool RRN);//retorna los datos del registro
    unsigned int searchIndex(int);//Retorna el offset del indice del registro
    vector<Campo>& getCampos();
};
