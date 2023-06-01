#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "Usuario.h"

using namespace std;

void crearUsuario(vector<Usuario>& listaUsuarios);
void leerUsuario(const vector<Usuario>& listaUsuarios);
void actualizarUsuario(vector<Usuario>& listaUsuarios);
void eliminarUsuario(vector<Usuario>& listaUsuarios);

#endif

