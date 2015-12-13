#include "record.h"
#include "campo.h"
#include <cstring>
#include <string>
#include <iostream>
//using std::string;
using namespace std;

Record::Record(vector<Campo>& campos)
{
    data = new vector<char*>();
    this->campos = campos;
    data->resize(campos.size());
}
Record::~Record(){
    data->~vector();
}
void Record::setCampos(vector<Campo>& campos){
    this->campos = campos;
    data = new vector<char*>();
    data->resize(campos.size());
}

void Record::setData(int campo, char* text){
    int size = campos.at(campo).size;
    if(strlen(text) <= size){
        cout << "CAMPO: = " << campo << endl;
        data->at(campo) = text;
        cout << data->at(campo) << endl;
    }
}
void Record::setData(char* rawdata[]){
    for(int i = 0; i < campos.size(); i++){
        data->at(i) = rawdata[i];
    }
}
const string Record::toString()const{
    string retval = "";
    for(int i = 0; i < data->size(); i++){
        retval += data->at(i);
    }
    return retval;
}
