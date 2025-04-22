// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "Zone.h"
#include <vector>
#include <string>

class Board {
private:
    std::vector<Zone> zones;

public:
    // Costruttore: carica la configurazione di default
    Board();

    // Ritorna riferimento alla zona (per controlli avanzati)
    Zone& getZone(const int& nZone);

    // Stampa su console tutte le zone con i loro livelli
    void display() const;
};

#endif // BOARD_H
