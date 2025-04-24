#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <string>
#include <vector>
#include <iostream>
#include "Mazzo.h"
#include "Oggetti.h"
#include "Zone.h"

class Giocatore {
private:
    std::string nome;                // Nome del giocatore
    Zone* zona;                        // Zona in cui si trova il giocatore (per esempio, mappa o posizione)
    Mazzo carte;         // carte in mano
    std::vector<std::string> carteGiocate;  // Carte giocate durante il turno
    std::string oggetto;

public:
    bool spostato = false;
    // Costruttore
    Giocatore(const std::string& nome, Zone& zona) : nome(nome), zona(&zona) { }

    // Metodi per gestire il mazzo del giocatore
    int pescaCarta(Mazzo& mazzo);
    bool giocaCarta(std::string carta, int num);
    void svuotaMano(); // Svuota la mano del giocatore
    void mostraAzioni();
    void spostaConOggetto(Oggetti& oggetti, Zone& zone);
    int getNumeroCarte() { return carte.getNumeroCarte(); }

    // Getter e Settera
    std::string getNome() const { return nome; };
    int getZona() const { return zona->number; };
    void setZona(Zone nuovaZona) { zona = &nuovaZona; };

    // Mostra stato del giocatore
    void mostraStato();
};

#endif