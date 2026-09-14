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
    void menu(Nodo* normal) {
        int Cantidad;
        bool Terminar = false;
        while (Terminar == false) {
            cout << " Indique la cantidad de pacientes a atender ";
            cin >> Cantidad;
            if (Cantidad >= 1) {
				for (int i = 0; i < Cantidad; i++) {
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
                        normal = normal->eliminarPacienteIndice(normal, i);
                        normal->ObtenerPacienteSiguiente();
					}
					else {
						cout << "No hay más pacientes en espera." << endl;
						break;
					}
				}
                break;
			}
            else {
                cout << "Cantidad inválida. Intente nuevamente." << endl;
            }
        }
    }
};