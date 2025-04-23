#ifndef MAZZO_H
#define MAZZO_H

#include <vector>
#include <string>
#include <algorithm>
#include <random>

class Mazzo {
private:
    std::vector<std::string> carte;
    int fascisti;

public:
    Mazzo(); // Costruttore per inizializzare il mazzo
    void Mazzo_Default();
    void mostraCarte();
    void aggiungiFascisti();
    int getFascisti() const;
    std::string pescaCarta(); // Pesca una carta dal mazzo
    void aggiungiCarta(std::string card);
    void svuotaMazzo() { carte.clear(); } // Svuota il mazzo

    // Aggiungiamo il metodo shuffle
    void shuffle();
};

#endif
