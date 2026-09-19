#include "Paciente.hpp"
#include "Nodo.hpp"
#include "Departamento.hpp"
#include "Lector.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class lector {
public:
    Nodo* cargarDepartamento() {
        ifstream archivo("pacientes.txt");
        if (archivo.fail()) {
            cerr << endl;
            exit(1);
        }
        Nodo* cabeza = nullptr;
        Nodo* actual = nullptr;
        string token0, token1, token2, token3;
        while (getline(archivo, token0, ';') &&
            getline(archivo, token1, ';') &&
            getline(archivo, token2, ';') &&
            getline(archivo, token3, '\n')) {
            Departamento d(token3);
            bool existe = false;
            Nodo* aux = cabeza;
            while (aux != nullptr) {
                if (aux->verDepartamento().getTipo() == d.getTipo()) {
                    existe = true;
                    break;
                }
                aux = aux->ObtenerPacienteSiguiente();
            }
            if (existe == false) {
                Nodo* nuevoNodo = new Nodo(d);
                if (cabeza == nullptr) {
                    cabeza = nuevoNodo;
                    actual = nuevoNodo;
                }
                else {
                    actual->SetNodoSiguiente(nuevoNodo);
                    actual = nuevoNodo;
                }
            }
        }
        archivo.close();
        return cabeza;
    }
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
                actual->SetNodoSiguiente(nuevoNodo);
                actual = nuevoNodo;
            }
        }

        archivo.close();
        return cabeza;
    }
    Nodo* eliminarPaciente(string nombre, Nodo* n, Paciente p) {
        while (n != nullptr) {
            if (n->verPaciente().getNombre() == nombre) {
				n->ObtenerPacienteSiguiente()->SetNodoSiguiente(nullptr);
            }
            n = n->ObtenerPacienteSiguiente();
        }
        return n;
    }
    int contar(int numero) {
        return numero;
    }
};