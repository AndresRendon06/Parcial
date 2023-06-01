#include "Usuario.h"

void Usuario::escribirEnArchivo(ofstream& archivo) {
    archivo << nombre << '\n';
    archivo << documento << '\n';
    archivo << correo << '\n';
}

void Usuario::leerDeArchivo(ifstream& archivo) {
    getline(archivo, nombre);
    getline(archivo, documento);
    getline(archivo, correo);
}
