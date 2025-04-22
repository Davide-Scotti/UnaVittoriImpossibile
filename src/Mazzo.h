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
    void aggiungiFascista();
    int getFascisti() const;

    // Aggiungiamo il metodo shuffle
    void shuffle();
};

#endif
