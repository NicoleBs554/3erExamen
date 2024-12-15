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

Owners* ownerPtr = nullptr;
int ownerCount = 0;
Pets* petPtr = nullptr;
int petCount = 0;

int main(){
    Consola();
    return 0;
}