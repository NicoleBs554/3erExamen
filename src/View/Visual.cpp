#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../Model/COwners.h"
#include "../Model/CPets.h"
#include "../Controller/FOwner.cpp"
#include "../Controller/FPets.cpp"
using namespace std;

void Consola() {
    string nombreArchivoOwners = "./bin/Owners.csv";
    string nombreArchivoPets = "./bin/Pets.csv";
    char confirmar = 0;
    int opcion = 0;

    Owners* ownerPtr = nullptr;
    int ownerCount = 0;

    Pets* petPtr = nullptr;
    int petCount = 0;

    leerOwners(nombreArchivoOwners);
    leerPets(nombreArchivoPets);

    do {
        cout << "¿Que archivo desea gestionar?" << endl;
        cout << "1. Owners" << endl;
        cout << "2. Pets" << endl;
        cout << "3. Cerrar el programa" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: 
                int ownerOption;
                do {
                    cout << "Seleccione una opcin para Owners:" << endl;
                    cout << "1. Leer Owners" << endl;
                    cout << "2. Guardar Owners" << endl;
                    cout << "3. Insertar Owner" << endl;
                    cout << "4. Actualizar Owner" << endl;
                    cout << "5. Borrar Owner" << endl;
                    cout << "6. Volver al menu principal" << endl;
                    cin >> ownerOption;

                    switch (ownerOption) {
                        case 1:
                            leerOwners(nombreArchivoOwners);
                            cout << "Owners leidos correctamente." << endl;
                            break;
                        case 2:
                            cout << "¿Desea guardar los cambios realizados? (s/n): ";
                            cin >> confirmar;
                            if (confirmar == 's' || confirmar == 'S') {
                                guardarOwners(nombreArchivoOwners);
                                cout << "Guardados correctamente." << endl;
                            } else {
                                cout << "No se guardaron los cambios." << endl;
                            }
                            break;
                        case 3:
                            insertarOwners();
                            break;
                        case 4: {
                            string cedula;
                            cout << "Ingrese la cedula del owner a actualizar: ";
                            cin >> cedula;
                            actualizarOwners(cedula);
                            break;
                        }
                        case 5: {
                            string cedula;
                            cout << "Ingrese la cedula del owner a borrar: ";
                            cin >> cedula;
                            borrarOwners(cedula);
                            break;
                        }
                        case 6:
                            break;
                        default:
                            cout << "Opcion no valida." << endl;
                    }
                } while (ownerOption != 6);
                break;

            case 2: 
                int petOption;
                do {
                    cout << "Seleccione una opcion para Pets:" << endl;
                    cout << "1. Leer Pets" << endl;
                    cout << "2. Guardar Pets" << endl;
                    cout << "3. Insertar Pet" << endl;
                    cout << "4. Actualizar Pet" << endl;
                    cout << "5. Borrar Pet" << endl;
                    cout << "6. Volver al menu principal" << endl;
                    cin >> petOption;

                    switch (petOption) {
                        case 1:
                            leerPets(nombreArchivoPets);
                            cout << "Pets leidos correctamente." << endl;
                            break;
                        case 2:
                            cout << "¿Desea guardar los cambios realizados? (s/n): ";
                            cin >> confirmar;
                            if (confirmar == 's' || confirmar == 'S') {
                                guardarPets(nombreArchivoPets);
                                cout << "Guardados correctamente." << endl;
                            } else {
                                cout << "No se guardaron los cambios." << endl;
                            }
                            break;
                        case 3:
                            insertarPets();
                            break;
                        case 4: {
                            string pets_id;
                            cout << "Ingrese el ID de la mascota a actualizar: ";
                            cin >> pets_id;
                            actualizarPets(pets_id);
                            break;
                        }
                        case 5: {
                            string pets_id;
                            cout << "Ingrese el ID de la mascota a borrar: ";
                            cin >> pets_id;
                            borrarPets(pets_id);
                            break;
                        }
                        case 6:
                            break;
                        default:
                            cout << "Opcion no valida." << endl;
                    }
                } while (petOption != 6);
                break;

            case 3:
                cout << "Cerrando el programa..." << endl;
                break;

            default:
                cout << "Opcion no válida. Por favor, seleccione 1, 2 o 3." << endl;
        }
    } while (opcion != 3);

    delete[] ownerPtr;
    delete[] petPtr;
}