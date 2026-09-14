#pragma once
#include <string> 

using namespace std;

class Paciente {
private:
    string ID;
    string Nombre;
    int Edad;
    string Servicio;
public:
    Paciente() {
        this->ID = "";
        this->Nombre = "";
        this->Edad = 0;
        this->Servicio = "";
    }

    Paciente(string ID, string Nombre, int Edad, string Servicio) {
        this->ID = ID;
        this->Nombre = Nombre;
        this->Edad = Edad;
        this->Servicio = Servicio;
    }

	string getID() {
		return this->ID;
	}

	string getNombre() {
		return this->Nombre;
	}

	int getEdad() {
		return this->Edad;
	}

    string getServicio() {
        return this->Servicio;
    }

    ~Paciente() {}
};