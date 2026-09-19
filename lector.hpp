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
        Nodo* p1 = cabeza;
        while (p1 != nullptr && p1->ObtenerPacienteSiguiente() != nullptr) {
            Nodo* p2 = p1;
            while (p2->ObtenerPacienteSiguiente() != nullptr) {
                if (p1->verPaciente().getID() == p2->ObtenerPacienteSiguiente()->verPaciente().getID() && p1->verPaciente().getNombre() == p2->ObtenerPacienteSiguiente()->verPaciente().getNombre() && p1->verPaciente().getEdad() == p2->ObtenerPacienteSiguiente()->verPaciente().getEdad() && p1->verPaciente().getServicio() == p2->ObtenerPacienteSiguiente()->verPaciente().getServicio()) {
                    Nodo* nodoAEliminar = p2->ObtenerPacienteSiguiente();
                    p2->SetNodoSiguiente(nodoAEliminar->ObtenerPacienteSiguiente());
                    delete nodoAEliminar;
                }
                else {
                    p2 = p2->ObtenerPacienteSiguiente();
                }
            }
            p1 = p1->ObtenerPacienteSiguiente();
        }

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