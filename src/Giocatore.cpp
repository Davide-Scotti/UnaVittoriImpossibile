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

void Giocatore::spostaConOggetto(Oggetti& oggetti, Zone& zone) {
    oggetti.get_Oggetti();

    int n = 0;
    std::cout << "1) Munizioni " << oggetti.nMunizioni << std::endl;
    std::cout << "2) Pozioni " << oggetti.nPozioni << std::endl;
    std::cout << "3) Cittadini " << oggetti.nCivili << std::endl;
    std::cout << "Inserisci (numero) oggetto da spostare: ";
    std::cin >> n;


    if(n == 1 && oggetti.nMunizioni > 0){
        oggetti.Remove_Munizioni();
        oggetto = "Munizioni";
    }else if (n == 2 && oggetti.nPozioni > 0){
        oggetti.Remove_Pozioni();
        oggetto = "Pozioni";
    }else if(n == 3 && oggetti.nCivili > 0){
        oggetti.Remove_Civili();
        oggetto = "Cittadini";
    }else{
        std::cout << "Oggetto non disponibile o non valido, ti muoverai senza per punizione." << std::endl;
    }

    if(zona.name == zone.name){
        setZona(zone);
    }else if(oggetto == ""){
        setZona(zone);
    }
    
    std::cout << nome << " si è spostato in " << zone.name << " con " << oggetto << std::endl;

    //TODO assegno l'oggetto alla zona in cui sono

    oggetto = ""; 
}

void Giocatore::mostraStato() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Zona: " << zona.number << std::endl;
    std::cout << "Carte in mano: ";

    carte.mostraCarte();  
}

void Giocatore::mostraAzioni() {
    std::cout << "Carte disponibili: ";
    carte.mostraCarte();  
}
