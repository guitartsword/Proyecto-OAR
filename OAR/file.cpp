#include "file.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "campo.h"
using namespace std;

File::File(string filepath, string nombre):
    nombre(nombre)
{
    if(filepath.substr(filepath.length()-4,filepath.length()) != ".OAR"){
        cout<< filepath.substr(filepath.length()-4,filepath.length())<<endl;
        filepath += ".OAR";
    }
    cout<<filepath.c_str()<<endl;
    file.open(filepath.c_str(), ios_base::out);
}
File::~File(){
    file.close();
}
void File::saveHeader(vector<Campo>* campos){
    char* buffer;
    int buffer_size=0;
    buffer_size += 1 + nombre.size();//El tamaño del nombre 1byte + El nombre
    buffer_size += campos->size() * (30 +1 + 1 + 1); //cantidad de campos * (Nombre + tipo + tamaño + llave primaria)
    buffer_size += 3; // Bytes en el Availist

    buffer = new char[1];
    buffer[0] = nombre.size();
    cout << "prearando pa escribir" << endl;
    file.write(buffer,1);
    delete[] buffer;
    cout << "finalizo primera escritura" << endl;

    buffer = new char[nombre.size()];
    strcpy(buffer, nombre.c_str());
    file.write(buffer, nombre.size());
    delete[] buffer;
    for(int i = 0; i < campos->size(); i++){
        //Nombre del campo
        buffer = new char[30];
        strcpy(buffer, campos->at(i).name);
        file.write(buffer, 30);
        delete[] buffer;

        //TIPO
        buffer = new char[1];
        buffer[0] =  campos->at(i).type;
        file.write(buffer, 1);
        delete[] buffer;

        //Tamaño del campo
        buffer = new char[1];
        if(campos->at(i).type != DEC)
            buffer[0] =  campos->at(i).size;
        else
            buffer[0] =  campos->at(i).size_dec;
        file.write(buffer, 1);
        delete[] buffer;

        //Es llave primaria?
        buffer = new char[1];
        buffer[0] =  campos->at(i).key;
        file.write(buffer, 1);
        delete[] buffer;
    }

    //ESCRIBIR UN ENTERO EN BINARIO

    //file.write(buffer,nombre.size());
    /*
    buffer[cursor] = nombre.size();
    buffer[++cursor] = nombre.c_str();
    for(int i = 0; i < campos->size(); i++){
        buffer[cursor+=nombre.size()] = campos->at(i).name;
        buffer[cursor+=30] = campos->at(i).type;
        if(campos->at(i).type != DEC)
            buffer[cursor+=4] = campos->at(i).size
        else
            buffer[cursor+=4] = campos->at(i).size_dec;
        buffer[++cursor] = campos->at(i).key;
    }
    */
    file.flush();
}

void File::addRecord(string){
    //Escribir Registro del disco
}

void File::updateFile(){
    //Actualizar Registro del disco
}

void File::deleteRecord(int){
    //Borrar Registro del archivo
}
