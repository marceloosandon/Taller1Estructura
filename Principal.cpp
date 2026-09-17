#include <iostream>
#include "Nodo.hpp"
#include "Paciente.hpp"
#include "Departamento.hpp"
#include "lector.hpp"
#include <string>
using namespace std;

int main() {
    bool Terminar = false;
    int opcion;
    int contador = 0;
    lector l;
	Nodo* pacientes = nullptr;
    Nodo* Departamentos = nullptr;
    Nodo* personas = l.cargar();
    Nodo* aux = personas;
    Nodo* respaldo = aux;
    int contadorCiclo = personas->obtenerSize(personas);
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
            respaldo = aux;
            while (respaldo != nullptr) {
                Paciente pe = respaldo->verPaciente();
                contador++;
                cout << contador << ". " << pe.getID() << " - " << pe.getNombre() << endl;
                respaldo = respaldo->ObtenerPacienteSiguiente();
            }
            if (contadorCiclo > 0) {
                cout << " Indique la cantidad de pacientes a atender: ";
                cin >> Cantidad;
                cout << " === ATENDIENDO PACIENTES === " << endl;
            }
            if (Cantidad > 0 && contadorCiclo > 0) {
                for (int i = 0; i < Cantidad; i++) {
                    if (aux != nullptr) {
                        Paciente p = aux->verPaciente();
                        cout << "ID: " << p.getID() << endl;
                        cout << "Nombre: " << p.getNombre() << endl;
                        cout << "Edad: " << p.getEdad() << endl;
                        cout << "Servicio: " << p.getServicio() << "\n" << endl;
                        if (pacientes == nullptr) {
                            pacientes = new Nodo(p);
                        }
                        else {
                            pacientes->InsertarPacienteFinal(p);
                        }

                        aux = aux->eliminarPacientePrimero(aux);
                    }
                    else {
                        cout << "No hay mas pacientes en espera." << endl;
                        break;
                    }
                }
                contadorCiclo = contadorCiclo - Cantidad;
            }
            if (contadorCiclo <= 0) {
                cout << "" << endl;
                cout << "No existen Personas o Atendiste a todas" << endl;
            }
        }
        else if (opcion == 2) {
            contador = 0;
            Departamentos = l.cargarDepartamento();
            if (Departamentos->obtenerSize(Departamentos) > 0) {
                cout << " === DEPARTAMENTOS/SERVICIOS === " << endl;
                while (Departamentos != nullptr) {
                    Departamento r = Departamentos->verDepartamento();
                    contador++;
                    cout << contador << ". " << r.getTipo() << endl;
                    Departamentos = Departamentos->ObtenerPacienteSiguiente();
                }
            }
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