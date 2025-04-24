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

void Mazzo::ResetAndAdd(){
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

    fascisti++;
    for(int i = 0; i < fascisti; i++){
        carte.push_back("Fascista");
    }
}

void Mazzo::mostraCarte() {
    for (const auto& carta : carte)
        std::cout << carta << " ";
    std::cout << std::endl;
}

void Mazzo::aggiungiFascisti() {
    for(int i = 0; i < fascisti; i++)
        carte.push_back("Fascista");
}

int Mazzo::getFascisti() const {
    return fascisti;
}

std::string Mazzo::pescaCarta() {
    if (carte.empty()) {

        // Incremento il numero della giornata
        fascisti++;
        Mazzo_Default();
        aggiungiFascisti();
    }

    std::string carta = carte.back();
    carte.pop_back(); 
    return carta;
}

void Mazzo::aggiungiCarta(std::string card) {
    carte.push_back(card);
}

bool Mazzo::hasCarte(const std::string& carta, int n) {
    int i = 0;

    for(auto& c : carte) {
        if(c == carta) {
           i++;
        }
    }

    return i >= n;
}

void Mazzo::giocaCarte(std::string carta, int num){

    for (auto it = carte.begin(); it != carte.end() && num > 0;) {
        if (*it == carta) {
            it = carte.erase(it);  
            --num;               
        } else {
            ++it;                 
        }
    }
}


void Mazzo::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(carte.begin(), carte.end(), g);
}
