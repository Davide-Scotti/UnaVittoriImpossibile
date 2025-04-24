#ifndef MAZZO_H
#define MAZZO_H

#include <vector>
#include <string>
#include <algorithm>
#include <random>

class Mazzo {
private:
    std::vector<std::string> carte;
    
public:
    int fascisti = 3;
    Mazzo(); // Costruttore per inizializzare il mazzo
    void Mazzo_Default();
    void ResetAndAdd();
    void mostraCarte();
    void aggiungiFascisti();
    int getFascisti() const;
    std::string pescaCarta(); // Pesca una carta dal mazzo
    void aggiungiCarta(std::string card);
    void svuotaMazzo() { carte.clear(); } // Svuota il mazzo
    bool hasCarte(const std::string& carta, int n); // Controlla se il mazzo ha una carta specifica
    void giocaCarte(std::string carta, int num);
    int getNumeroCarte() { return carte.size(); } // ritorna numero di carte

    // Aggiungiamo il metodo shuffle
    void shuffle();
};

#endif
