// Giocatore.cpp
#include "Giocatore.h"
#include <iostream>

void Giocatore::pescaCarta(Mazzo& mazzo) {
   std::string carta = mazzo.pescaCarta(); 

   if (carta != "") {
    // La carta viene aggiunta alla mano internamente alla classe Mazzo
        std::cout << nome << " ha pescato: " << carta << std::endl;
    } else {
        std::cout << nome << " non ha più carte da pescare." << std::endl;
    }

   carte.aggiungiCarta(carta); 
}

bool Giocatore::giocaCarta(std::string carta, int num){
    if(!carte.hasCarte(carta, num)); 
        return false;

    carte.giocaCarte(carta, num);
}

void Giocatore::svuotaMano() {
    carte.svuotaMazzo(); 
}

void Giocatore::mostraStato() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Zona: " << zona << std::endl;
    std::cout << "Carte in mano: ";

    carte.mostraCarte();  
}

void Giocatore::mostraAzioni() {
    std::cout << "Carte disponibili: ";
    carte.mostraCarte();  
}
