#include "file.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <QDebug>
#include "campo.h"
using namespace std;


File::File(string filepaths, string nombre, bool openfile):
    nombre(nombre),
    write(write),
    filepath(filepaths)
{
    if(filepath.length() < 4)
        filepath += ".OAR";
    else if(filepath.substr(filepath.length()-4,filepath.length()) != ".OAR")
        filepath += ".OAR";
    cout<<filepath.c_str()<<endl;
    output.open(filepath.c_str(), ios::out | ios::app);
    input.open(filepath.c_str(), ios::in);
    if(openfile){
        output.seekp(0,output.end);
        cout <<"File size: "<< output.tellp() << endl;
        output.seekp(0,output.beg);
        reCalcHeaderSize();
        cout <<"headerSize: "<< header_size<<endl;
    }
}
File::~File(){
    input.close();
    output.close();
}
void File::saveHeader(vector<Campo> &campos){
    char* buffer;
    header_size = 0;
    /*
        buffer_size += 1 + nombre.size();//El tamaño del nombre 1byte + El nombre                         30    +  1  +     1   +       1
        buffer_size += 1 + campos.size() * (33); //1byte por cantidad de campos + cantidad de campos * (Nombre + tipo + tamaño + llave primaria)
        buffer_size += 3; // Bytes en el Availist

     * HEADER_SIZE = 1byte + valor obtenido del primer byte
     *              +1byte + cantidad->campos obtendio del byte anterior * 33
     *              + 3 del tamaño del availist
     * En resumen HEADER_SIZE = 5bytes + namesize + campos*33


    */
    buffer = new char[31];

    //Se guarda el tamaño del nombre
    buffer[0] = nombre.size();
    output.write(buffer,1);

    //El nombre del archivo de registros
    buffer = new char[nombre.size()];
    strcpy(buffer, nombre.c_str());
    output.write(buffer, nombre.size());

    //Cantidad de campos
    buffer[0] = campos.size();
    output.write(buffer, 1);

    for(unsigned int i = 0; i < campos.size(); i++){
        //Nombre del campo
        strcpy(buffer, campos.at(i).name);
        buffer[30] = '\0';
        output.write(buffer, 30);
        header_size+=30;
        //TIPO
        buffer[0] =  campos.at(i).type;
        output.write(buffer, 1);
        //Tamaño del campo
        if(campos.at(i).type != DEC)
            buffer[0] =  campos.at(i).size;
        else
            buffer[0] =  campos.at(i).size_dec;
        output.write(buffer, 1);
        //ES LLAVE PRIMARIA?
        buffer[0] =  campos.at(i).key;
        output.write(buffer, 1);
    }
    //AVAILIST
    unsigned int availList =0;
    output.write(reinterpret_cast<const char *>(&availList),3);
    delete[] buffer;
    output.flush();
    qDebug() << "Header_size in file is: " << output.tellp();
    header_size = 5 + nombre.size() + campos.size()*33;
    qDebug() << "Header_size in should be: " << header_size;
}


void File::addRecord(string record, int RRN){
    output.flush();
    //Actualizar el Avail List
    updateAvail(RRN);
    //Escribir Registro del disco en una posicion especifica
    output.seekp(header_size + ((RRN-1)*record.size()),ios::beg);
    output.write(record.c_str(),record.size());
}

void File::appendRecord(string record){
    //Escribir append un registro
    output.flush();
    output.seekp(0,output.end);
    output.write(record.c_str(),record.size());
}

void File::updateFile(){
    //Actualizar Registro del disco
}

void File::deleteRecord(int){
    //Borrar Registro del archivo
}

void File::reCalcHeaderSize(){
    header_size = 5;
    int defined_size = 0;
    input.seekg(0,input.beg);
    input.read(reinterpret_cast<char*>(&defined_size),1);
    header_size+=defined_size;
    cout << header_size << endl;
    input.seekg(defined_size+1,input.beg);
    defined_size = 0;
    input.read(reinterpret_cast<char*>(&defined_size),1);
    header_size+= defined_size*33;
    cout << header_size << endl << endl;
}
int File::getRRN(){
    input.seekg(header_size-3,ios::beg);
    int RRN = 0;
    input.read(reinterpret_cast<char *>(&RRN),3);
    cout << "RRN: "<< RRN << endl;
    return RRN;
}
bool File::isOpen()const{
    return output.is_open() || input.is_open();
}
int File::recordCount(){
    output.flush();
    input.seekg(0,input.end);
    int fileSize = input.tellg();
    int recordsSize = fileSize - header_size;
    return (recordsSize/recordSize());
}

int File::recordSize(){
    int offset = 1, recordSize = 0;
    int defined_size = 0;

    input.seekg(0,input.beg);
    input.read(reinterpret_cast<char*>(&defined_size),1);
    offset+=defined_size;

    defined_size = 0;
    input.seekg(offset,input.beg);
    input.read(reinterpret_cast<char*>(&defined_size),1);
    offset+=32;
    for(int i = 0; i < defined_size; i++){
        int fieldSize = 0;
        input.seekg(offset,input.beg);
        input.read(reinterpret_cast<char*>(&fieldSize),1);
        recordSize+=fieldSize;
        offset+=33;
    }
    return recordSize;
}
vector<Campo>& File::getCampos(){
    output.flush();
    int defined_size = 0;
    input.seekg(0,input.beg);
    input.read(reinterpret_cast<char*>(&defined_size),1);
    int offset=defined_size+1;

    defined_size = 0;
    input.seekg(offset,input.beg);
    input.read(reinterpret_cast<char*>(&defined_size),1);
    campos.clear();
    for(int i = 0; i < defined_size; i++){
        char* name;
        input.read(name, 30);
        FieldType type;
        input.read(reinterpret_cast<char* >(&type),1);
        int size = 0;
        input.read(reinterpret_cast<char*>(&size), 1);
        bool key = 0;
        input.read(reinterpret_cast<char*>(&key), 1);
        Campo temp;
        strcpy(temp.name, name);
        temp.type = type;
        if(temp.type == DEC)
            temp.size_dec = size;
        else
            temp.size = size;
        temp.key = key;
        campos.push_back(temp);
    }
    return campos;
}
string File::getRecord(int ID){
    //RECORDAR HACERLO DESPUES
    return "AUN NO HAY NADA";
}
void File::updateAvail(int key){
    //Se lee lo que hay en el RRN antes de que sea modificado
    int temp;
    input.seekg(header_size+((key-1)*recordSize())+1,ios::beg);
    input.read(reinterpret_cast<char *>(&temp),3);
    //Se escribe el nuevo header
    output.seekp(header_size-3,ios::beg);
    unsigned int newAvail =temp;
    output.write(reinterpret_cast<const char *>(&newAvail),3);
    output.flush();
}
