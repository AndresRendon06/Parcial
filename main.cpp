#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Usuario.h"
#include "Menu.h"

using namespace std;

int main() {
    try {
        // Crear una lista de usuarios
		vector<Usuario> listaUsuarios;
/*
		// Agregar usuarios a la lista
		int cantidadUsuarios;
        cout << "Ingrese cuantos Usuarios quiere tener en la lista: " << endl;
        cin >> cantidadUsuarios;
        cin.ignore(); //Ignorar el salto de linea y permitir que el getline funcione correctamente 
        
        for(int i=0; i < cantidadUsuarios; i++){
        	Usuario usuario; //para almacenar datos en la memoria.
        	
        	cout << "Ingrese el nombre del Usuario " << i + 1 << ": ";
			getline(cin, usuario.nombre);
			
			cout << "Ingrese el documento del Usuario " << i + 1 << ": ";
			getline(cin, usuario.documento);
						
			cout << "Ingrese el correo del Usuario " << i + 1 << ": ";
			getline(cin, usuario.correo);
			
			listaUsuarios.push_back(usuario);
			cout << endl;
		}
		*/
        	
        // Leer la lista de usuarios desde un archivo
        
        ifstream archivoEntrada("lista de usuarios.txt");
        if (archivoEntrada.is_open()) {
            vector<Usuario> listaUsuariosLeidos;
            Usuario usuarioLeido;
            
           while (!archivoEntrada.eof()) {
                usuarioLeido.leerDeArchivo(archivoEntrada);
                if (!usuarioLeido.nombre.empty()) {
                    listaUsuarios.push_back(usuarioLeido);
                    usuarioLeido = Usuario();
                }
            }

            archivoEntrada.close();
                        
      		listaUsuarios = listaUsuariosLeidos;

            // Mostrar los usuarios leídos
            cout << "Usuarios leidos desde el archivo:" << endl;
            for (const Usuario& usuario : listaUsuariosLeidos) {
                cout << "Nombre: " << usuario.nombre << endl;
                cout << "Documento: " << usuario.documento << endl;
                cout << "Correo: " << usuario.correo << endl;
                cout << endl;
            }
   
        } else {
            throw runtime_error("No se pudo abrir el archivo para lectura");
        }
        
    	//Menu
    	int opcion;
    	do{
    		cout << "==== MENU ====" << endl;
    		cout << "1. Crear usuario." << endl;
    		cout << "2. Leer usuario." << endl;
    		cout << "3. Actualizar usuario." << endl;
    		cout << "4. Eliminar usuario." << endl;
    		cout << "0. Salir." << endl;
    		cout << "Ingrese una opcion." << endl;
    		cin >> opcion;
    		cin.ignore();
    	
    		switch (opcion){
    			case 1: 
    				crearUsuario(listaUsuarios);
    				break;
    			case 2:
    				leerUsuario(listaUsuarios);
    				break;
    			case 3:
    				actualizarUsuario(listaUsuarios);
    				break;
    			case 4: 
    				eliminarUsuario(listaUsuarios);
    				break;
    			case 0:
    				cout << "Saliendo del programa..." << endl;
    				break;
    			default:
    				cout << "Opcion invalida. Intente nuevamente." << endl;
			}
			cout << endl;
		} while (opcion != 0);
		
		// Escribir la lista de usuarios en un archivo
		if (!listaUsuarios.empty()){	
       		ofstream archivoSalida("lista de usuarios.txt", ios::trunc);
			if (archivoSalida.is_open()) {
   		 		for (Usuario& usuario : listaUsuarios) {
        		usuario.escribirEnArchivo(archivoSalida);
        		archivoSalida << "\n\n";  // Separador entre usuarios
    			}
    			archivoSalida.close();
    		cout << "Lista de usuarios escrita en el archivo 'lista de usuarios.txt'" << endl;
			} else {
    	throw runtime_error("No se pudo abrir el archivo para escritura");
			}
		}
    } 
	catch (const exception& e){
        cout << "Excepcion capturada: " << e.what() << endl;
        return 1;
    }

    return 0;
}







