#pragma once
#include "Paciente.hpp"
#include "Departamento.hpp"

class Nodo {
private:
    Paciente p;
    Departamento d;
    Nodo* N1;
public:
    Nodo(Departamento d);
    Nodo(Paciente p);

    Nodo* ObtenerPacienteSiguiente();
    Nodo* registrarPaciente(Paciente p);

    void SetNodoSiguiente(Nodo* N1);

    int obtenerSize(Nodo* n);

    bool estaVacio();

	void InsertarPacienteIndice(Paciente p, int indice);

    Nodo* InsertarPacienteFinal(Paciente p);

    Paciente VerPacienteInverso(Nodo* n, int numeroactual);

    Paciente verPacienteIndice(int indice);

	void vaciarLista();

    Paciente verPaciente();

    Departamento verDepartamento();

	Nodo* eliminarPacienteIndice(Nodo* n, int indice);

    Nodo* eliminarPacientePrimero(Nodo* n);

    ~Nodo() {}
};