#include "file.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

File::File(string filepath, string nombre):
    nombre(nombre)
{
    cout<<filepath;
    file.open(filepath.c_str());
    file.close();
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
