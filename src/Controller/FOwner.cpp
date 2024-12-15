#pragma once
#include "../Model/COwners.h"
#include <string>
#include <cctype> 
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

extern Owners* ownerPtr; 
extern int ownerCount;

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

void leerOwners(const string &ownerFile) {
    ifstream archivoOwner("../bin/Owners.csv");
    string line;

    if (!archivoOwner.is_open()) {
        cout << "No se pudo abrir el archivo " << ownerFile << endl;
        return;
    }

    getline(archivoOwner, line); 
    while (getline(archivoOwner, line)) {
        Owners owner; 
        stringstream ss(line);
        string tempStr;

        getline(ss, tempStr, ',');
        if (esNumero(tempStr)) {
            owner.setOwner_id(convertirAEntero(tempStr)); 
        } else {
            cout << "Error: ID de propietario no válido: " << tempStr << endl;
            continue;
        } 
        getline(ss, tempStr, ',');
        owner.setNombre(tempStr);
        getline(ss, tempStr, ',');
        owner.setApellido(tempStr);
        getline(ss, tempStr, ',');
        owner.setDireccion(tempStr);
        getline(ss, tempStr, ',');
        owner.setTelefono(tempStr);
        getline(ss, tempStr, ',');
        owner.setEmail(tempStr); 

        Owners* temp = new Owners[ownerCount + 1]; 
        for (int i = 0; i < ownerCount; ++i) {
            temp[i] = ownerPtr[i];
        }
        temp[ownerCount] = owner;
        delete[] ownerPtr;
        ownerPtr = temp;
        ownerCount++;
    }
    archivoOwner.close();
}

void guardarOwners(const string &ownersFile) {
    ofstream file("../bin/Owners.csv");
    file << "CedulaOwner, Nombre, Apellido, Direccion, Telefono, Email\n"; 
    for (int i = 0; i < ownerCount; i++) {
        file << ownerPtr[i].getOwner_id() << ","
             << ownerPtr[i].getNombre() << ","
             << ownerPtr[i].getApellido() << ","
             << ownerPtr[i].getDireccion() << ","
             << ownerPtr[i].getTelefono() << ","
             << ownerPtr[i].getEmail() << "\n"; 
    }
    file.close();
}

void insertarOwners() {
    Owners owner; 
    cout << "Ingrese los datos del owner: " << endl;
    string cedulaOwner, nombre, apellido, direccion, telefono, email; 
    cin >> cedulaOwner >> nombre >> apellido >> direccion >> telefono >> email;
    if (esNumero(cedulaOwner)) {
        owner.setOwner_id(convertirAEntero(cedulaOwner)); 
    } else {
        cout << "Error: La cédula ingresada no es un número válido." << endl;
        return; 
    }
    owner.setNombre(nombre);
    owner.setApellido(apellido);
    owner.setDireccion(direccion);
    owner.setTelefono(telefono);
    owner.setEmail(email);

    cout << "¿Desea confirmar la inserción del owner? (si/no): ";
    char confirmacion;
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        Owners* temp = new Owners[ownerCount + 1]; 
        for (int i = 0; i < ownerCount; i++) {
            temp[i] = ownerPtr[i];
        }

        temp[ownerCount] = owner;
        delete[] ownerPtr;
        ownerPtr = temp;
        ownerCount++;
        guardarOwners("../bin/Owners.csv");
        cout << "Owner insertado" << endl;
    } else {
        cout << "Inserción cancelada" << endl;
    }
}

void actualizarOwners(const string &cedula) {
    if (!esNumero(cedula)) {
        cout << "Error: La cédula ingresada no es un número válido." << endl;
        return; 
    }

    int cedulaInt = convertirAEntero(cedula); 

    for (int i = 0; i < ownerCount; i++) {
        if (ownerPtr[i].getOwner_id() == cedulaInt) { 
            Owners original = ownerPtr[i]; 
            Owners &owner = ownerPtr[i]; 
            cout << "Ingrese nuevos datos: " << endl;
            string nombre, apellido, direccion, telefono, email; 
            cin >> nombre >> apellido >> direccion >> telefono;
            cin.ignore();
            getline(cin, email); 
            owner.setNombre(nombre);
            owner.setApellido(apellido);
            owner.setDireccion(direccion);
            owner.setTelefono(telefono);
            owner.setEmail(email); 
            cout << "¿Desea confirmar la actualización del owner? (si/no): ";
            char confirmacion;
            cin >> confirmacion;

            if (confirmacion == 's' || confirmacion == 'S') {
                guardarOwners("../bin/Owners.csv");
                cout << "Cambios confirmados y guardados" << endl;
            } else {
                ownerPtr[i] = original; 
                cout << "Cambios revertidos" << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}
void borrarOwners(const string &cedula) {
    if (!esNumero(cedula)) {
        cout << "Error: La cédula ingresada no es un número válido." << endl;
        return; 
    }
    int cedulaInt = convertirAEntero(cedula); 
    for (int i = 0; i < ownerCount; i++) {
        if (ownerPtr[i].getOwner_id() == cedulaInt) { 
            cout << "¿Está seguro de que desea eliminar el owner con cédula " << cedula << "? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                Owners* temp = new Owners[ownerCount - 1]; 
                for (int j = 0, k = 0; j < ownerCount; j++) {
                    if (j != i) {
                        temp[k++] = ownerPtr[j]; 
           
                    }
                }
                delete[] ownerPtr; 
                ownerPtr = temp; 
                ownerCount--; 
                guardarOwners("../bin/Owners.csv"); 
                cout << "Owner ha sido eliminado" << endl;
            } else {
                cout << "Eliminacion cancelada" << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}
           