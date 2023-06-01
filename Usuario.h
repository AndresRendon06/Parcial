#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <fstream>


using namespace std;

class Usuario {
public:
    string nombre;
    string documento;
    string correo;

    void escribirEnArchivo(ofstream& archivo); //of = open file = abrir archivo  //&= referencia que permite a eEA modificar el archivo 
    void leerDeArchivo(ifstream& archivo); //if= input file = ingresar archivo
};

#endif