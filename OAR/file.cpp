#include "file.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include "campo.h"
using namespace std;


File::File(string filepath, string nombre, bool write):
    nombre(nombre),
    write(write)
{
    if(filepath.length() < 4)
        filepath += ".OAR";
    else if(filepath.substr(filepath.length()-4,filepath.length()) != ".OAR")
        filepath += ".OAR";
    cout<<filepath.c_str()<<endl;
    if(write)
        file.open(filepath.c_str(), ios::out);
    else{
        file.open(filepath.c_str(), ios::in);
        reCalcHeaderSize();
    }
}
File::~File(){
    file.close();
}
void File::saveHeader(vector<Campo>* campos){
    char* buffer;
    header_size = 0;
    /*
        buffer_size += 1 + nombre.size();//El tamaño del nombre 1byte + El nombre                         30    +  1  +     1   +       1
        buffer_size += 1 + campos->size() * (33); //1byte por cantidad de campos + cantidad de campos * (Nombre + tipo + tamaño + llave primaria)
        buffer_size += 3; // Bytes en el Availist

     * HEADER_SIZE = 1byte + valor obtenido del primer byte
     *              +1byte + cantidad->campos obtendio del byte anterior * 33
     *              + 3 del tamaño del availist
     * En resumen HEADER_SIZE = 5bytes + namesize + campos*33


    */
    buffer = new char[31];

    //Se guarda el tamaño del nombre
    buffer[0] = nombre.size();
    file.write(buffer,1);

    //El nombre del archivo de registros
    buffer = new char[nombre.size()];
    strcpy(buffer, nombre.c_str());
    file.write(buffer, nombre.size());

    //Cantidad de campos
    buffer[0] = campos->size();
    file.write(buffer, 1);

    for(unsigned int i = 0; i < campos->size(); i++){
        //Nombre del campo
        strcpy(buffer, campos->at(i).name);
        buffer[30] = '\0';
        file.write(buffer, 30);
        header_size+=30;
        //TIPO
        buffer[0] =  campos->at(i).type;
        file.write(buffer, 1);
        //Tamaño del campo
        if(campos->at(i).type != DEC)
            buffer[0] =  campos->at(i).size;
        else
            buffer[0] =  campos->at(i).size_dec;
        file.write(buffer, 1);
        //ES LLAVE PRIMARIA?
        buffer[0] =  campos->at(i).key;
        file.write(buffer, 1);
    }
    //AVAILIST
    unsigned int availList = 0;
    file.write(reinterpret_cast<const char *>(&availList),3);
    delete[] buffer;
    file.flush();

    header_size = 5 + nombre.size() + campos->size()*33;
}


void File::addRecord(string record, int offset){
    //Escribir Registro del disco en una posicion especifica
    file.seekp(header_size + offset,ios::beg);
    file.write(record.c_str(),record.size());
    file.flush();
}

void File::appendRecord(string record){
    //Escribir append un registro
    file.flush();
    file.seekp(0,ios::end);
    cout << record.c_str() << " also file is open: " << file.is_open() << endl;
    file << record.c_str();
}

void File::updateFile(){
    //Actualizar Registro del disco
}

void File::deleteRecord(int){
    //Borrar Registro del archivo
}

void File::reCalcHeaderSize(){
    header_size = 5;
    int defined_size;
    file.read(reinterpret_cast<char *>(&defined_size),1);
    header_size+=defined_size;
    file.seekg(defined_size+1);
    file.read(reinterpret_cast<char *>(&defined_size),1);
    header_size+= defined_size*33;
}
int File::getRRN(){
    file.seekg(header_size-3);
    int RRN;
    file.read(reinterpret_cast<char *>(&RRN),3);
    return RRN;
}
