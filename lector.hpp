#include "Paciente.hpp"
#include "Nodo.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class lector {
public:
    Nodo* cargar() {
        ifstream archivo("pacientes.txt");
		if (archivo.fail()) {
			cerr << "No se pudo abrir el archivo." << endl;
			exit(1);
		}
        Nodo* cabeza = nullptr; 
        Nodo* actual = nullptr;

        string token0, token1, token2, token3;

        while (getline(archivo, token0, ';') &&
            getline(archivo, token1, ';') &&
            getline(archivo, token2, ';') &&
            getline(archivo, token3, '\n')) {

            int entero = stoi(token2);

            Paciente p(token0, token1, entero, token3);

            Nodo* nuevoNodo = new Nodo(p);

            if (cabeza == nullptr) {
                cabeza = nuevoNodo;
                actual = nuevoNodo;
            }
            else {
                actual->SetNodo(nuevoNodo);
                actual = nuevoNodo;
            }
        }

        archivo.close();
        return cabeza;
    }
};