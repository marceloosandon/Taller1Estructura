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
    int ver = 0;
    lector l;
	Nodo* pacientes = nullptr;
    Nodo* pacientesAux = nullptr;
    Nodo* Departamentos = nullptr;
    Nodo* personas = l.cargar();
    Nodo* aux = personas;
    Nodo* respaldo = aux;
    int contadorCiclo = personas->obtenerSize(personas);
    if (personas == nullptr) {
        cout << "No está el archivo de pacientes.txt, colocalo en la misma ubicación" << endl;
    }
    while (Terminar == false) {
        cout << "" << endl;
        cout << " === HOSPITAL MARMAJA === " << endl;
        cout << "1. Atender Pacientes " << endl;
        cout << "2. Ver Departamento " << endl;
        cout << "3. Revisar Historial de Atencion" << endl;
        cout << "4. Salir " << endl;
        cout << "" << endl;
        cout << "Seleccionar opcion: ";
        cin >> opcion;
        cout << "" << endl;
        if (opcion == 1) {
            contador = 0;
            int Cantidad = 0;
            cout << " === PACIENTES EN ESPERA === " << endl;
            respaldo = aux;
            while (respaldo != nullptr) {
                Paciente pe = respaldo->verPaciente();
                contador++;
                cout << contador << ". " << pe.getID() << " - " << pe.getNombre() << endl;
                respaldo = respaldo->ObtenerPacienteSiguiente();
            }
            cout << "" << endl;
            if (contadorCiclo > 0) {
                cout << "Indique la cantidad de pacientes a atender: ";
                cin >> Cantidad;
                cout << "" << endl;
                if (Cantidad > 0) {
                    cout << " === ATENDIENDO PACIENTES === " << endl;
                }
            }
            if (Cantidad > 0 && contadorCiclo > 0) {
                for (int i = 0; i < Cantidad; i++) {
                    if (aux != nullptr) {
                        Paciente p = aux->verPaciente();
                        cout << "ID: " << p.getID() << endl;
                        cout << "Nombre: " << p.getNombre() << endl;
                        cout << "Edad: " << p.getEdad() << endl;
                        cout << "Servicio: " << p.getServicio() << endl;
                        cout << "" << endl;
                        cout << "Paciente enviado a " << p.getServicio( )<< endl;
                        cout << "" << endl;
                        if (pacientes == nullptr) {
                            pacientes = new Nodo(p);
                        }
                        else {
                            pacientes->InsertarPacienteFinal(p);
                        }
                        aux = aux->eliminarPacientePrimero(aux);
                    }
                    else {
                        break;
                    }
                }
                contadorCiclo = contadorCiclo - Cantidad;
            }
            if (pacientesAux == nullptr) {
                pacientesAux = pacientes;
            }
        }
        else if (opcion == 2) {
            contador = 0;
            Departamentos = l.cargarDepartamento();
            if (Departamentos != nullptr) {
                if (Departamentos->obtenerSize(Departamentos) > 0) {
                    cout << " === DEPARTAMENTOS/SERVICIOS === " << endl;
                    cout << "" << endl;
                    while (Departamentos != nullptr) {
                        Departamento r = Departamentos->verDepartamento();
                        contador++;
                        cout << contador << ". " << r.getTipo() << endl;
                        Departamentos = Departamentos->ObtenerPacienteSiguiente();
                    }
                }
                Departamentos = l.cargarDepartamento();
                cout << "" << endl;
                cout << "Seleccionar opcion: ";
                cin >> ver;
                cout << "" << endl;
                contador = 0;
                if (ver > 0 && ver <= Departamentos->obtenerSize(Departamentos)) {
                    pacientes = pacientesAux;
                    if (pacientes != nullptr) {
                        for (int i = 0; i < ver; i++) {
                            if (i < ver - 1) {
                                Departamento r = Departamentos->verDepartamento();
                                contador++;
                                Departamentos = Departamentos->ObtenerPacienteSiguiente();
                            }
                        }
                        string letra = Departamentos->verDepartamento().getTipo();
                        for (char& c : letra) {
                            c = toupper(c);
                        }
                        cout << " === ESTADO " << letra << " === " << endl;
                        contador = 0;
                        while (pacientes != nullptr) {
                            if (Departamentos->verDepartamento().getTipo() == pacientes->verPaciente().getServicio()) {
                                contador++;
                            }
                            pacientes = pacientes->ObtenerPacienteSiguiente();
                        }
                        if (contador > 0) {
                            pacientes = pacientesAux;
                            cout << "Pacientes en el estado de " << Departamentos->verDepartamento().getTipo() << ": " << contador << endl;
                            while (pacientes != nullptr) {
                                if (Departamentos->verDepartamento().getTipo() == pacientes->verPaciente().getServicio()) {
                                    cout << pacientes->verPaciente().getNombre() << " (" << pacientes->verPaciente().getEdad() << ") " << endl;
                                }
                                pacientes = pacientes->ObtenerPacienteSiguiente();
                            }
                        }
                        else {
                            cout << "No hay Pacientes Guardados en el departamento de " << Departamentos->verDepartamento().getTipo() << endl;
                        }
                    }
                    else {
                        cout << "No hay Pacientes Guardados en algun departamento" << endl;
                    }
                }
                else {
                    cout << "Rango Invalido, seleccione otro" << endl;
                }
            }
            else {
                cout << "No existen departamentos validos" << endl;
            }
        }
        else if (opcion == 3) {
            pacientes = pacientesAux;
            if (pacientes == nullptr) {
                cout << "No hay Pacientes Guardados" << endl;
                cout << "" << endl;
            }
            else {
                cout << " === HISTORIAL DE ULTIMAS ATENCIONES EN EL HOSPITAL" << endl;
                cout << "" << endl;
                contador = 0;
                while (pacientes != nullptr) {
                    if (contador < pacientes->obtenerSize(pacientes)) {
                        Paciente mostrarI = pacientes->VerPacienteInverso(pacientes, contador);
                        contador++;
                        cout << "Nombre : " << mostrarI.getNombre() << " | Edad: " << mostrarI.getEdad() << " | Departamento: " << mostrarI.getServicio() << endl;
                    }
                    else {
                        break;
                    }
                }
                cout << "" << endl;
            }
        }
        else if (opcion == 4) {
            Terminar = true;
			cout << "Hasta luego :D." << endl;
            break;
        }
    }
    return 0;
}