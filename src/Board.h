// Board.h
#ifndef BOARD_H
#define BOARD_H

#include "RisorseGlobali.h"
#include "Zone.h"
#include "Giocatore.h"
#include "Mazzo.h"
#include <string>
#include <vector>

struct PointBoard {
  bool IsCover = false;
  bool IsBarricate = false;

  PointBoard(bool isCover, bool IsBarricate)
      : IsCover(isCover), IsBarricate(IsBarricate) {}
};

class Board {
private:
  std::vector<Zone> zones;
  std::vector<Giocatore> player;
  RisorseGlobali risorseGlobali;
  std::vector<PointBoard> pointBoard;
  Mazzo mazzoPesca;
  int nCarte = 0; // numero di carte a giocatore
  int nGiornata = 0; // numero di giornata
  bool isHard = false;

public:
  // Costruttore: carica la configurazione di default
  Board();

  // Ritorna riferimento alla zona (per controlli avanzati)
  Zone &getZone(const int &nZone);

  // Aggiunte
  bool aggiungiFascistaAZona(Zone& zona);
  bool aggiungiBarricataAZona(Zone& zona);
  bool aggiungiMunizioneAZona(Zone& zona);
  bool aggiungiPozioneAZona(Zone& zona);
  bool aggiungiCivileAZona(Zone& zona);

  // Rimozioni
  bool rimuoviFascistaDaZona(Zone& zona);
  bool rimuoviMunizioneDaZona(Zone& zona);
  bool rimuoviPozioneDaZona(Zone& zona);
  bool rimuoviCivileDaZona(Zone& zona);

  // Lancio di n dadi
  std::vector<int> lanciaDadi(int numDadi);

  void mostraCarte();
  int getGiorno() { return nGiornata; }
  int getNumPlayers() const { return static_cast<int>(player.size()); }
  Giocatore& getPlayer(int idx) { return player[idx]; }
  Oggetti getOggettiInZona(Zone& zona) { return zona.oggetti; }
  int getPunteggioBarricata();
  void MostraZonaGiocatore(Zone& zona) { zona.mostraZona(); }
  int getNumZona(int nZona) const { return zones[nZona].number; }
  
  // Inizializzazione board
  void initalizeGame();
  void initalizeZone();
  void initalizePointBoard();
  void initalizeGiocatori();
  void initalizeMani();


  bool stillAlive();

  void drawPointBoard() const;
  void display() const;
};

#endif // BOARD_H
