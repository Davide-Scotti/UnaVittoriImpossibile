#include "Mazzo.h"
#include <iostream>

Mazzo::Mazzo() : fascisti(0) {
    Mazzo_Default(); // Inizializziamo il mazzo con il metodo di default
}

void Mazzo::Mazzo_Default() {
    // Inizializza le carte
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 5; j++) {
            if(j == 0)
                carte.push_back("Munizione");
            else if(j == 1)
                carte.push_back("Civile");
            else if(j == 2)
                carte.push_back("Pozione");
            else if(j == 3)
                carte.push_back("Barricata");
            else if(j == 4)
                carte.push_back("Sparo");
        }
    }

    shuffle();
}

void Mazzo::mostraCarte() {
    for (const auto& carta : carte)
        std::cout << carta << " ";
    std::cout << std::endl;
}

void Mazzo::aggiungiFascista() {
    fascisti++;
}

int Mazzo::getFascisti() const {
    return fascisti;
}

// Implementazione della funzione shuffleMazzo
void Mazzo::shuffle() {
    // Usando un generatore di numeri casuali
    std::random_device rd;
    std::mt19937 g(rd());

    // Mescola il mazzo con std::shuffle
    std::shuffle(carte.begin(), carte.end(), g);
}
