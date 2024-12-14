#pragma once
#include <string>
using namespace std;

class Pets{
private:
    int Pets_id, Owners_id;
    string Pets_Name, Especie, Genero, Edad;
public:
    Pets() : Pets_id(0), Owners_id(0), Pets_Name(""), Especie(""), Genero(""), Edad("") {}

    Pets(int pets_id, int owners_id, string pets_name, string especie, string genero, string edad)
        : Pets_id(pets_id), Owners_id(owners_id), Pets_Name(pets_name), Especie(especie), Genero(genero), Edad(edad) {}

    int getPets_id() const { return Pets_id; }
    int getOwner_id() const { return Owners_id; }
    string getPets_Name() const { return Pets_Name; }
    string getEspecie() const { return Especie; }
    string getGenero() const { return Genero; }
    string getEdad() const { return Edad; }

    void setPets_id(const int &pets_id) { this->Pets_id = pets_id; }
    void setOwner_id(const int &owners_id) { this->Owners_id = owners_id; }
    void setPets_Name(const string &pets_name) { this->Pets_Name = pets_name; }
    void setEspecie(const string &especie) { this->Especie = especie; }
    void setGenero(const string &genero) { this->Genero = genero; }
    void setEdad(const string &edad) { this->Edad = edad; }
};
