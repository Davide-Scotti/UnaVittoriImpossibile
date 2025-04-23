// Giocatore.cpp
#include "Giocatore.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

void Giocatore::mostraStato() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Zona: " << zona << std::endl;
    std::cout << "Carte in mano: ";

    carte.mostraCarte();  
}
