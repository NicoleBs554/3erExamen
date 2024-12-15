#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "./Model/COwners.h"
#include "./Model/CPets.h"
#include "./Controller/FOwner.cpp"
#include "./Controller/FPets.cpp"
#include "./View/Visual.cpp"
using namespace std;

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

Owners* ownerPtr = nullptr;
int ownerCount = 0;
Pets* petPtr = nullptr;
int petCount = 0;

int main(){
    Consola();
    return 0;
}