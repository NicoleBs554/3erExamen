#pragma once
#include "../Model/CPets.h"
#include <string>
#include <cctype> 
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

extern Pets* petPtr; 
extern int petCount;

bool esNumero(const string& str) {
    if (str.empty()) return false; 
    for (char c : str) {
        if (!isdigit(c)) return false; 
    }
    return true;
}

int convertirAEntero(const string& str) {
    int resultado = 0;
    for (char c : str) {
        resultado = resultado * 10 + (c - '0'); 
    }
    return resultado;
}

void leerPets(const string &petsFile) {
    ifstream archivoPets("../bin/Pets.csv");
    string line;

    if (!archivoPets.is_open()) {
        cout << "No se pudo abrir el archivo " << petsFile << endl;
        return;
    }

    getline(archivoPets, line); 
    while (getline(archivoPets, line)) {
        Pets pet; 
        stringstream ss(line);
        string tempStr;

        getline(ss, tempStr, ',');
        if (esNumero(tempStr)) {
            pet.setPets_id(convertirAEntero(tempStr)); 
        } else {
            cout << "Error: ID de mascota no válido: " << tempStr << endl;
            continue; 
        }
        getline(ss, tempStr, ',');
        if (esNumero(tempStr)) {
            pet.setOwner_id(convertirAEntero(tempStr)); 
        } else {
            cout << "Error: ID de propietario no válido: " << tempStr << endl;
            continue; 
        }
        getline(ss, tempStr, ',');
        pet.setPets_Name(tempStr); 
        getline(ss, tempStr, ',');
        pet.setEspecie(tempStr); 
        getline(ss, tempStr, ',');
        pet.setGenero(tempStr); 
        getline(ss, tempStr, ',');
        pet.setEdad(tempStr); 

        Pets* temp = new Pets[petCount + 1]; 
        for (int i = 0; i < petCount; ++i) {
            temp[i] = petPtr[i];
        }
        temp[petCount] = pet;
        delete[] petPtr;
        petPtr = temp;
        petCount++;
    }
    archivoPets.close();
}

void guardarPets(const string &petsFile) {
    ofstream file("../bin/Pets.csv");
    file << "PetsID, OwnerID, Pets_Name, Especie, Genero, Edad\n"; 
    for (int i = 0; i < petCount; i++) {
        file << petPtr[i].getPets_id() << ","
             << petPtr[i].getOwner_id() << ","
             << petPtr[i].getPets_Name() << ","
             << petPtr[i].getEspecie() << ","
             << petPtr[i].getGenero() << ","
             << petPtr[i].getEdad() << "\n"; 
    }
    file.close();
}

void insertarPets() {
    Pets pet; 
    cout << "Ingrese los datos de la mascota: " << endl;
    string pets_id, owner_id, pets_name, especie, genero, edad; 
    cin >> pets_id >> owner_id >> pets_name >> especie >> genero >> edad;
    if (esNumero(pets_id)) {
        pet.setPets_id(convertirAEntero(pets_id)); 
    } else {
        cout << "Error: ID de mascota no válido." << endl;
        return; 
    }
    if (esNumero(owner_id)) {
        pet.setOwner_id(convertirAEntero(owner_id)); 
    } else {
        cout << "Error: ID de propietario no válido." << endl;
        return; 
    }
    pet.setPets_Name(pets_name); 
    pet.setEspecie(especie); 
    pet.setGenero(genero); 
    pet.setEdad(edad); 

    cout << "¿Desea confirmar la insercion de la mascota? (si/no): ";
    char confirmacion;
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        Pets* temp = new Pets[petCount + 1]; 
        for (int i = 0; i < petCount; i++) {
            temp[i] = petPtr[i];
        }

        temp[petCount] = pet;
        delete[] petPtr;
        petPtr = temp;
        petCount++;
        guardarPets("../bin/Pets.csv");
        cout << "Mascota insertada" << endl;
    } else {
        cout << "Inserción cancelada" << endl;
    }
}

void actualizarPets(const string &pets_id) {
    if (!esNumero(pets_id)) {
        cout << "Error: ID de mascota no valido." << endl;
        return; 
    }
    int pets_id_int = convertirAEntero(pets_id); 
    for (int i = 0; i < petCount; i++) {
        if (petPtr[i].getPets_id() == pets_id_int) { 
            Pets original = petPtr[i]; 
            Pets &pet = petPtr[i]; 
            cout << "Ingrese nuevos datos: " << endl;
            string owner_id, pets_name, especie, genero, edad; 
            cin >> owner_id >> pets_name >> especie >> genero >> edad;
            if (esNumero(owner_id)) {
                pet.setOwner_id(convertirAEntero(owner_id)); 
            } else {
                cout << "Error: ID de propietario no válido." << endl;
                return; 
            }
            pet.setPets_Name(pets_name); 
            pet.setEspecie(especie); 
            pet.setGenero(genero); 
            pet.setEdad(edad); 
            cout << "¿Confirma los cambios? (si/no): ";
            char confirmacion;
            cin >> confirmacion;

            if (confirmacion == 's' || confirmacion == 'S') {
                guardarPets("../bin/Pets.csv");
                cout << "Cambios confirmados y guardados" << endl;
            } else {
                petPtr[i] = original; 
                cout << "Cambios revertidos" << endl;
            }
            return;
        }
    }
    cout << "Mascota no encontrada." << endl;
}
void borrarPets(const string &pets_id) {
    if (!esNumero(pets_id)) {
        cout << "Error: ID de mascota no válido." << endl;
        return; 
    }
    int pets_id_int = convertirAEntero(pets_id);
    for (int i = 0; i < petCount; i++) {
        if (petPtr[i].getPets_id() == pets_id_int) { 
            cout << "¿Está seguro de que desea eliminar la mascota con ID " << pets_id << "? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                Pets* temp = new Pets[petCount - 1]; 
                for (int j = 0, k = 0; j < petCount; j++) {
                    if (j != i) {
                        temp[k++] = petPtr[j]; 
                    }
                }
                delete[] petPtr; 
                petPtr = temp; 
                petCount--; 
                guardarPets("../bin/Pets.csv");
                cout << "Mascota ha sido eliminada" << endl;
            } else {
                cout << "Eliminación cancelada" << endl;
            }
            return;
        }
    }
    cout << "Mascota no encontrada." << endl;
}