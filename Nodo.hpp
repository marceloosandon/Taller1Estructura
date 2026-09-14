#pragma once
#include "Paciente.hpp"

class Nodo {
private:
    Paciente p;
    Nodo* N1;
public:
    Nodo(Paciente p);

    Nodo* ObtenerPacienteSiguiente();
    Nodo* registrarPaciente(Paciente p);

    void SetNodoSiguiente(Nodo* N1);

    int obtenerSize(Nodo* n);

    bool estaVacio();

	void InsertarPacienteIndice(Paciente p, int indice);

    Nodo* InsertarPacienteFinal(Paciente p);

    Paciente verPacienteIndice(int indice);

	void vaciarLista();

    Paciente verPaciente();

	Nodo* eliminarPacienteIndice(Nodo* n, int indice);

    Nodo* eliminarPacientePrimero(Nodo* n);

    ~Nodo() {}
};