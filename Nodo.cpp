#include "Departamento.hpp"
#include "Nodo.hpp"

Nodo::Nodo(Paciente p) {
    this->p = p;
	this->N1 = nullptr;
}

Nodo::Nodo(Departamento d) {
	this->d = d;
	this->N1 = nullptr;
}

Nodo* Nodo::ObtenerPacienteSiguiente() {
    return this->N1;
}

Nodo* Nodo::registrarPaciente(Paciente p) {
    this->p = p;
    return this;
}

void Nodo::SetNodoSiguiente(Nodo* N1) {
    this->N1 = N1;
}

Paciente Nodo::verPaciente() {
    return this->p;
}

Departamento Nodo::verDepartamento() {
	return this->d;
}

int Nodo::obtenerSize(Nodo* n) {
	int size = 0;
	while (n != nullptr) {
		size++;
		n = n->ObtenerPacienteSiguiente();
	}
	return size;
}

bool Nodo::estaVacio() {
	return this->N1 == nullptr;
}

void Nodo::InsertarPacienteIndice(Paciente p, int indice) {
	if ((indice == 0) || (estaVacio())) {
		Nodo* nuevoNodo = new Nodo(p);
		nuevoNodo->SetNodoSiguiente(this->N1);
		this->N1 = nuevoNodo;
	}
	else {
		Nodo* actual = this;
		for (int i = 0; i < indice - 1 && actual != nullptr; i++) {
			actual = actual->ObtenerPacienteSiguiente();
		}
		if (actual != nullptr) {
			Nodo* nuevoNodo = new Nodo(p);
			nuevoNodo->SetNodoSiguiente(actual->ObtenerPacienteSiguiente());
			actual->SetNodoSiguiente(nuevoNodo);
		}
	}
}

Paciente Nodo::verPacienteIndice(int indice) {
	Nodo* actual = this;
	for (int i = 0; i < indice && actual != nullptr; i++) {
		actual = actual->ObtenerPacienteSiguiente();
	}
	if (actual != nullptr) {
		return actual->verPaciente();
	}
	else {
		return Paciente("", "", 0, "");
	}
}

void Nodo::vaciarLista() {
	Nodo* actual = this;
	while (actual != nullptr) {
		Nodo* siguiente = actual->ObtenerPacienteSiguiente();
		delete actual;
		actual = siguiente;
	}
}

Nodo* Nodo::eliminarPacienteIndice(Nodo* n, int indice) {
	if (n == nullptr) return nullptr;

	if (indice == 0) {
		Nodo* siguiente = n->ObtenerPacienteSiguiente();
		delete n;
		return siguiente;
	}
	Nodo* actual = n;
	Nodo* anterior = nullptr;
	for (int i = 0; i < indice && actual != nullptr; i++) {
		anterior = actual;
		actual = actual->ObtenerPacienteSiguiente();
	}
	if (actual != nullptr) {
		anterior->SetNodoSiguiente(actual->ObtenerPacienteSiguiente());
		delete actual;
	}
	return n;
}
Nodo* Nodo::eliminarPacientePrimero(Nodo* n) {
	if (!estaVacio()) {
		Nodo* siguiente = n->ObtenerPacienteSiguiente();
		delete n;
		return siguiente;
	}
	else {
		return nullptr;
	}
}

Nodo* Nodo::InsertarPacienteFinal(Paciente pa) {
	Nodo* aux = this;
	while (aux->ObtenerPacienteSiguiente() != nullptr) {
		aux = aux->ObtenerPacienteSiguiente();
	}
	Nodo* nuevo = new Nodo(pa);
	aux->SetNodoSiguiente(nuevo);
	return nuevo;
}