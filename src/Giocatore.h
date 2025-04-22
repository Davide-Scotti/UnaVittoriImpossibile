#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <string>
#include <vector>
#include "Mazzo.h"

class Giocatore {
private:
    std::string nome;                // Nome del giocatore
    int zona;                        // Zona in cui si trova il giocatore (per esempio, mappa o posizione)
    Mazzo carte;         // carte in mano
    std::vector<std::string> carteGiocate;  // Carte giocate durante il turno

public:
    // Costruttore
    Giocatore(const std::string& nome, int zona) 
    : nome(nome), zona(zona) { }

    // Metodi per gestire il mazzo del giocatore
    void pescaCarta();
    void giocaCarta(const std::string& carta);
    void mostraCarteGiocate();

    // Getter e Settera
    std::string getNome() const;
    int getZona() const;
    void setZona(int nuovaZona);

    // Mostra stato del giocatore
    void mostraStato();
};

void Giocatore::mostraStato() {
    std::cout << "Stato del giocatore: " << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Zona: " << zona << std::endl;
    std::cout << "Carte in mano: ";
    // Mostra le carte in mano (del mazzo del giocatore)
    // Puoi implementare un metodo mostraCarte() nel mazzo per fare questo
    mazzo.mostraCarte();  // Assumendo che ci sia una funzione mostraCarte nel mazzo
    std::cout << std::endl;

    std::cout << "Carte giocate: ";
    if (carteGiocate.empty()) {
        std::cout << "Nessuna carta giocata." << std::endl;
    } else {
        for (const auto& carta : carteGiocate) {
            std::cout << carta << " ";
        }
        std::cout << std::endl;
    }
}

#endif