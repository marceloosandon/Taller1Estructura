#include <iostream>
#include "Nodo.hpp"
#include "Paciente.hpp"
#include "lector.hpp"
#include <string>
using namespace std;

int main() {
    bool Terminar = false;
    int opcion;
    lector l;
    while (Terminar == false) {
        l.cargar();
        cout << " === HOSPITAL MARMAJA === " << endl;
        cout << "1. Atender Pacientes " << endl;
        cout << "2. Ver Departamento " << endl;
        cout << "3. Revisar Historial de Atencion" << endl;
        cout << "4. Salir " << endl;
        cin >> opcion;
        if (opcion == 1) {

        }
        else if (opcion == 2) {
            //ver departamentos
        }
        else if (opcion == 3) {
            //historial
        }
        else if (opcion == 4) {
            Terminar = true;
            break;
        }
    }
    return 0;
}