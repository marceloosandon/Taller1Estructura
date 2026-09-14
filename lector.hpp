#include "Paciente.hpp"
#include "Nodo.hpp"
#include "Lector.cpp"
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
    Nodo* menu(Nodo* normal, int cantidad) {
        bool Terminar = false;
        int contador = 0;
        Nodo* aux = normal;
        if (cantidad >= 1) {
			for (int i = 1; i < cantidad+1; i++) {
                if (i == 0) {
                    cout << " === ATENDIENDO PACIENTES === " << endl;
                }
				if (normal != nullptr) {
					Paciente p = normal->verPaciente();
					cout << "ID: " << p.getID() << endl;
                    cout << "Nombre: " << p.getNombre() << endl;
                    cout << "Edad: " << p.getEdad() << endl;
					cout << "Servicio: " << p.getServicio() << endl;
                    cout << "" << endl;
                    normal = normal->eliminarPacientePrimero(normal);
				}
				if (normal == nullptr) {
					cout << "No hay más pacientes en espera." << endl;
					return normal;
				}
			}
            contar(cantidad);
            return normal;
		}
        else {
            cout << "Cantidad inválida. Intente nuevamente." << endl;
            return nullptr;
        }
        contar(cantidad);
        return aux;
    }
    int contar(int numero) {
        return numero;
    }
};