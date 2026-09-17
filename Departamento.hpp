#pragma once
#include <string> 

using namespace std;

class Nodo;

class Departamento {
private:
	string Tipo;
	Nodo* Personas;

public:
	Departamento() {
		this->Tipo = "";
		this->Personas = nullptr;
	}

	Departamento(string tipo) {
		this->Tipo = tipo;
		this->Personas = nullptr;
	}

	string getTipo() {
		return this->Tipo;
	}

	Nodo* getPersonas() {
		return this->Personas;
	}

	~Departamento() {}
};