// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "RisorseGlobali.h"
#include "Zone.h"
#include <string>
#include <vector>

class Board {
private:
  std::vector<Zone> zones;
  RisorseGlobali risorseGlobali;

public:
  // Costruttore: carica la configurazione di default
  Board();

  // Ritorna riferimento alla zona (per controlli avanzati)
  Zone &getZone(const int &nZone);

  // Aggiunte
  bool aggiungiFascistaAZona(int numeroZona);
  bool aggiungiBarricataAZona(int numeroZona);
  bool aggiungiMunizioneAZona(int numeroZona);
  bool aggiungiPozioneAZona(int numeroZona);
  bool aggiungiCivileAZona(int numeroZona);

  // Rimozioni
  bool rimuoviFascistaDaZona(int numeroZona);
  bool rimuoviMunizioneDaZona(int numeroZona);
  bool rimuoviPozioneDaZona(int numeroZona);
  bool rimuoviCivileDaZona(int numeroZona);

  // Stampa su console tutte le zone con i loro livelli
  void display() const;
};

#endif // BOARD_H
