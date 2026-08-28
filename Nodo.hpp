#include "Paciente.hpp"
#include <string>

class Nodo {
private:
    Paciente p;
    Nodo* N;
public:
    Nodo(Paciente p);
    Nodo* ObtenerPacienteSiguiente();
    void registrarPaciente(Paciente p);
    void SetNodo(Nodo n);
    Paciente verPaciente();
    ~Nodo();
};