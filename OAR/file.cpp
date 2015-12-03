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
    header_size(0),
    write(write)
{
    if(filepath.substr(filepath.length()-4,filepath.length()) != ".OAR"){
        cout<< filepath.substr(filepath.length()-4,filepath.length())<<endl;
        filepath += ".OAR";
    }
    cout<<filepath.c_str()<<endl;
    if(write)
        file.open(filepath.c_str(), ios_base::out);
    else{
        file.open(filepath.c_str(), ios_base::in);
        calcHeaderSize();
    }
}
File::~File(){
    file.close();
}
void File::saveHeader(vector<Campo>* campos){
    char* buffer;
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
    for(int i = 0; i < campos->size(); i++){
        //Nombre del campo
        strcpy(buffer, campos->at(i).name);
        buffer[30] = '\0';
        file.write(buffer, 30);
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
}

void File::addRecord(string record){
    file.seekg(ios_base::end);
    file.write(record.c_str(),record.size());

}

void File::updateFile(){
    //Actualizar Registro del disco
}

void File::deleteRecord(int){
    //Borrar Registro del archivo
}

void File::calcHeaderSize(){
    header_size = 5;
    int defined_size;
    file.read(reinterpret_cast<char *>(&defined_size),1);
    header_size+=defined_size;
    file.seekg(defined_size+1);
    file.read(reinterpret_cast<char *>(&defined_size),1);
    header_size+= defined_size*33;
}
