#include "Menu.h"
#include "Usuario.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void crearUsuario(vector<Usuario>& listaUsuarios) {
    Usuario usuario;

    cout << "Ingrese el nombre del usuario: ";
    getline(cin, usuario.nombre);

    cout << "Ingrese el documento del usuario: ";
    getline(cin, usuario.documento);

    cout << "Ingrese el correo del usuario: ";
    getline(cin, usuario.correo);

    listaUsuarios.push_back(usuario);

	ofstream archivoSalida("lista de usuarios.txt", ios::app);
	if(archivoSalida.is_open()){
		usuario.escribirEnArchivo(archivoSalida);
		archivoSalida << "\n\n";
		archivoSalida.close();
		cout << "Usuario agregado correctamente. Lista de usuarios actualizada en tiempo real." << endl;
    } else {
        throw runtime_error("No se pudo abrir el archivo para escritura");
    }
}

void leerUsuario(const vector<Usuario>& listaUsuarios) {
    cout << "Usuarios:" << endl;

    for (const Usuario& usuario : listaUsuarios) {
        cout << "Nombre: " << usuario.nombre << endl;
        cout << "Documento: " << usuario.documento << endl;
        cout << "Correo: " << usuario.correo << endl;
        cout << endl;
    }
}

void actualizarUsuario(vector<Usuario>& listaUsuarios) {
    string documento;

    cout << "Ingrese el documento del usuario a actualizar: ";
    getline(cin, documento);

    for (Usuario& usuario : listaUsuarios) {
        if (usuario.documento == documento) {
            cout << "Ingrese el nuevo nombre del usuario: ";
            getline(cin, usuario.nombre);

            cout << "Ingrese el nuevo correo del usuario: ";
            getline(cin, usuario.correo);

            cout << "Usuario actualizado correctamente." << endl;
            return;
        }
    }

    cout << "No se encontrO un usuario con ese documento." << endl;
}

void eliminarUsuario(vector<Usuario>& listaUsuarios) {
    string documento;

    cout << "Ingrese el documento del usuario a eliminar: ";
    getline(cin, documento);

    for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); ++it) {
        if (it->documento == documento) {
            listaUsuarios.erase(it);
            
            ofstream archivoSalida("lista de usuarios.txt");
            if(archivoSalida.is_open()){
            	for(Usuario& usuario : listaUsuarios){
            		usuario.escribirEnArchivo(archivoSalida);
            		archivoSalida << "\n\n";
				}
				archivoSalida.close();
				cout << "Usuarios eliminado correctamente. " << endl;
			}
            else{
            	throw runtime_error("No se pudo abrir el archivo de escritura");
			}
			return;
        }
	}
    cout << "No se encontrO un usuario con ese documento." << endl;
}
