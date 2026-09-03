#include "Nodo.hpp"

Nodo::Nodo() {
    this->N = nullptr;
}

Nodo::Nodo(Paciente p) {
    this->p = p;
    this->N = nullptr;
}

Nodo* Nodo::ObtenerPacienteSiguiente() {
    return this->N;
}

void Nodo::registrarPaciente(Paciente p) {
    this->p = p;
}

void Nodo::SetNodo(Nodo* n) {
    this->N = n;
}

Paciente Nodo::verPaciente() {
    return this->p;
}