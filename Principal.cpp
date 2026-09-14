#include <iostream>
#include "Nodo.hpp"
#include "Paciente.hpp"
#include "lector.hpp"
#include <string>
using namespace std;

int main() {
    bool Terminar = false;
    int opcion;
    int contador = 0;
    lector l;
	Nodo* pacientes = nullptr;
    Nodo* personas = l.cargar();
    Nodo* aux = personas;
    Nodo* respaldo = aux;
    int contadorCiclo = 0;
    while (Terminar == false) {
        cout << " === HOSPITAL MARMAJA === " << endl;
        cout << "1. Atender Pacientes " << endl;
        cout << "2. Ver Departamento " << endl;
        cout << "3. Revisar Historial de Atencion" << endl;
        cout << "4. Salir " << endl;
        cin >> opcion;
        if (opcion == 1) {
            int Cantidad = 0;
            cout << " === PACIENTES EN ESPERA === " << endl;
            while (respaldo != nullptr) {
                Paciente pe = respaldo->verPaciente();
                contador = contador + 1;
                cout << contador << ". " << pe.getID() << " - " << pe.getNombre() << endl;
                respaldo = respaldo->ObtenerPacienteSiguiente();
            }
            cout << " Indique la cantidad de pacientes a atender ";
            cin >> Cantidad;
			aux = l.menu(aux, Cantidad);
            contador = l.contar(Cantidad);
            respaldo = aux;
            if (pacientes == nullptr) {
                pacientes = aux;
            }
            else {
                while (aux != nullptr) {
                    if (contadorCiclo < contador) {
                        pacientes->SetNodoSiguiente(aux);
                        aux = aux->ObtenerPacienteSiguiente();
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else if (opcion == 2) {
            //ver departamentos
        }
        else if (opcion == 3) {
            //historial
        }
        else if (opcion == 4) {
            Terminar = true;
			cout << "Hasta luego :D." << endl;
            break;
        }
    }
    return 0;
}