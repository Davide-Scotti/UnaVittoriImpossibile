#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <string>
#include <vector>
#include <iostream>
#include "Mazzo.h"

class Giocatore {
private:
    std::string nome;                // Nome del giocatore
    int zona;                        // Zona in cui si trova il giocatore (per esempio, mappa o posizione)
    Mazzo carte;         // carte in mano
    std::vector<std::string> carteGiocate;  // Carte giocate durante il turno

public:
    // Costruttore
    Giocatore(const std::string& nome, int zona) : nome(nome), zona(zona) { }

    // Metodi per gestire il mazzo del giocatore
    void pescaCarta(Mazzo& mazzo);
    void giocaCarta(const std::string& carta);
    void mostraCarteGiocate();
    void svuotaMano(); // Svuota la mano del giocatore

    // Getter e Settera
    std::string getNome() const;
    int getZona() const;
    void setZona(int nuovaZona);

    // Mostra stato del giocatore
    void mostraStato();
};

#endif