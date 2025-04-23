// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "RisorseGlobali.h"
#include "Zone.h"
#include "Giocatore.h"
#include "Mazzo.h"
#include <string>
#include <vector>

class Board {
private:
  std::vector<Zone> zones;
  std::vector<Giocatore> player;
  RisorseGlobali risorseGlobali;
  Mazzo mazzoPesca;
  int nCarte = 0; // numero di carte a giocatore
  int nGiornata = 0; // numero di giornata

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

  // Lancio di n dadi
  std::vector<int> lanciaDadi(int numDadi);

  void mostraCarte();
  int getGiorno() { return nGiornata; }

  // Inizializzazione board
  void initalizeGame();
  void initalizeZone();
  void initalizeGiocatori();
  void initalizeMani();

  bool stillAlive();

  // Stampa su console tutte le zone con i loro livelli
  void display() const;
};

#endif // BOARD_H
