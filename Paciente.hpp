#include <string>
#pragma once
using namespace std;

class Paciente {
private:
    string ID;
    string Nombre;
    int Edad;
    string Servicio;
public:
    Paciente(string ID, string Nombre, int Edad, string Servicio) {
        this->ID = ID;
        this->Nombre = Nombre;
        this->Edad=Edad;
        this->Servicio = Servicio;
    }
    ~Paciente();
};