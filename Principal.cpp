#include <iostream>
#include "Nodo.hpp"
#include "Paciente.hpp"
using namespace std;

int main() {
    bool Terminar = false;
    int opcion;
    while (Terminar == false) {
        cout << " === HOSPITAL MARMAJA === " << endl;
        cout << "1. Atender Pacientes " << endl;
        cout << "2. Ver Departamento " << endl;
        cout << "3. Revisar Historial de Atención" << endl;
        cout << "4. Salir " << endl;
        cin >> opcion;
        if (opcion == 1) {
            //atender los pacientes
        }
        else if (opcion == 2) {
            //ver departamentos
        }
        else if (opcion == 3) {
            //historial
        }
        else if (opcion == 4) {
            break;
        }
    }
    return 0;
}