#pragma once
#include "Paciente.hpp"

class Nodo {
private:
    Paciente p;
    Nodo* N;
public:
    Nodo();
    Nodo(Paciente p);

    Nodo* ObtenerPacienteSiguiente();
    void registrarPaciente(Paciente p);

    void SetNodo(Nodo* n);
    Paciente verPaciente();

    ~Nodo() {
    }
};