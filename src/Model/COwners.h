#pragma once
#include <string>
using namespace std;

class Owners{
private:
    int Owner_id;
    string Nombre, Apellido, Email, Direccion, Telefono;

public:
    Owners() : Owner_id(0), Nombre(""), Apellido(""), Telefono(""), Direccion(""), Email("") {}

    Owners(int cedulaOwner, string IdOwner, string nombre, string apellido, string telefono, string direccion, string email)
        : Owner_id(cedulaOwner), Nombre(nombre), Apellido(apellido), Telefono(telefono), Direccion(direccion), Email(email) {}
    
    int getOwner_id() const { return Owner_id; }
    string getNombre() const { return Nombre; }
    string getApellido() const { return Apellido; }
    string getTelefono() const { return Telefono; }
    string getDireccion() const { return Direccion; }
    string getEmail() const { return Email; }

    void setOwner_id(const string &cedulaOwner) { this->Owner_id = atoi(cedulaOwner.c_str()); }
    void setNombre(const string &nombre) { this->Nombre = nombre; }
    void setApellido(const string &apellido) { this->Apellido = apellido; }
    void setTelefono(const string &telefono) { this->Telefono = telefono; }
    void setDireccion(const string &direccion) { this->Direccion = direccion; }
    void setEmail(const string &email) { this->Email = email; }
};