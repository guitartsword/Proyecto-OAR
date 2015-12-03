#pragma once
#include "campo.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Record
{
    vector<Campo>* campos;
    vector <char*>* data;
public:
    Record(vector<Campo>*);
    ~Record();
    void setCampos(vector<Campo>* campos);
    void setData(int, char*);
    void setData(char**);
    const string toString()const;
};
