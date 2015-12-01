#include "file.h"
#include <fstream>
#include <string>
using namespace std;

File::File(string filepath, string nombre):
    nombre(nombre)
{
    file.open(filepath.c_str());
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
