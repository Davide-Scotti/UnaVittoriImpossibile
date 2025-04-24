// Board.cpp
#include "Board.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

Board::Board() {
  // Configurazione iniziale: nomi e livello max
  zones.emplace_back("Oltretorrente", 1);
  zones.emplace_back("Oltretorrente", 2);
  zones.emplace_back("Oltretorrente", 3);
  zones.emplace_back("Oltretorrente", 4);
  zones.emplace_back("Naviglio", 5);
  zones.emplace_back("Naviglio", 6);

  mazzoPesca.Mazzo_Default();
}

Zone &Board::getZone(const int &nZone) {
  auto it = std::find_if(zones.begin(), zones.end(),
                         [&](const Zone &z) { return z.number == nZone; });
  if (it == zones.end())
    throw std::runtime_error("Zona non trovata");
  return *it;
}

int Board::getPunteggioBarricata() {
  int punteggio = 0;

  for (const auto &score : pointBoard) {
      punteggio++;

      if(score.IsBarricate == true)
        break;
  }

  return punteggio;
}

bool Board::aggiungiFascistaAZona(Zone& zona) {
  if (risorseGlobali.usaFascista()) {
    zona.oggetti.Add_Fascisti();
    return true;
  }
  return false;
}

bool Board::aggiungiBarricataAZona(Zone& zona) {

  bool found = false;

  for(auto& score : pointBoard){
    if(score.IsBarricate == true){
      found = true;
      score.IsBarricate = false;
      break;
    }
  }

  if(found)
    zona.oggetti.Add_Barricata();

  return found;
}

bool Board::aggiungiMunizioneAZona(Zone& zona) {
  if (risorseGlobali.usaMunizione()) {
    zona.oggetti.Add_Munizioni();
    return true;
  }
  return false;
}

bool Board::aggiungiPozioneAZona(Zone& zona) {
  if (risorseGlobali.usaPozione()) {
    zona.oggetti.Add_Pozioni();
    return true;
  }
  return false;
}

bool Board::aggiungiCivileAZona(Zone& zona) {
  if (risorseGlobali.usaCivile()) {
    zona.oggetti.Add_Civili();
    return true;
  }
  return false;
}

bool Board::rimuoviFascistaDaZona(Zone& zona) {
  if(zona.oggetti.Remove_Fascisti())
    risorseGlobali.fascistiDisponibili++;
  return true;
}

bool Board::rimuoviMunizioneDaZona(Zone& zona) {
  if(zona.oggetti.Remove_Munizioni())
    risorseGlobali.munizioniDisponibili++;
  return true;
}

bool Board::rimuoviPozioneDaZona(Zone& zona) {
  if(zona.oggetti.Remove_Pozioni())
    risorseGlobali.pozioniDisponibili++;
  return true;
}

bool Board::rimuoviCivileDaZona(Zone& zona) {
  if(zona.oggetti.Remove_Civili())
    risorseGlobali.civiliDisponibili++;
  return true;
}

std::vector<int> Board::lanciaDadi(int numDadi) {
  std::vector<int> risultati;

  // Lancia i dadi e mostra i risultati
  std::cout << "Hai lanciato " << numDadi << " dado(i): ";
  for (int i = 0; i < numDadi; i++) {
      risultati.push_back(rand() % 6 + 1); // Genera un numero casuale tra 1 e 6
      std::cout << risultati.back() << " ";
  }

  std::cout << std::endl;

  return risultati;
}

void Board::mostraCarte(){
  mazzoPesca.mostraCarte();
}

void Board::initalizeGame(){

  initalizeZone();

  initalizePointBoard();

  initalizeGiocatori();

  initalizeMani();

  // Stampa lo stato iniziale del gioco
  for(int i = 0; i < player.size(); i++)
  {
      player[i].mostraStato();
  }
}

void Board::initalizeZone() {
   // Inserisco nelle zone gli oggetti ed i fasci
   std::vector<int> risultati;

   // Aggiungo i fascisti
   risultati = lanciaDadi(2);
   for (int i = 0; i < risultati.size(); i++) {
     aggiungiFascistaAZona(zones[risultati[i] - 1]);
   }
 
   // Aggiungo le munizioni
   risultati = lanciaDadi(2);
   for (int i = 0; i < risultati.size(); i++) {
     aggiungiMunizioneAZona(zones[risultati[i] - 1]);
   }
 
   // Aggiungo le pozioni
   risultati = lanciaDadi(2);
   for (int i = 0; i < risultati.size(); i++) {
    aggiungiPozioneAZona(zones[risultati[i] - 1]);
   }
 
   // Aggiungo i civili
   risultati = lanciaDadi(2);
   for (int i = 0; i < risultati.size(); i++) {
     aggiungiCivileAZona(zones[risultati[i] - 1]);
   }
}

void Board::initalizePointBoard() {
  std::cout << "Seleziona la difficoltà (0 per facile, 1 per difficile): ";
  std::cin >> isHard;

  int point = (isHard) ? 5 : 8;

  for(int i = 0; i < point; i++){
    pointBoard.push_back(PointBoard(false, false));
  }

  for(int i = 0; i < 8; i++){
    pointBoard.push_back(PointBoard(false, true));
  }

  pointBoard[0].IsCover = true;
}

void Board::initalizeGiocatori(){
   // Inserisci numero player
   int nPlayer = 0;
   std::cout << "inserisci il numero di giocatori: ";
   std::cin >> nPlayer;
 
   for(int i = 0; i < nPlayer; i++)
   {
     std::string name;
     std::cout << "inserisci il nome del giocatore: ";
     std::cin >> name;
     int numZona = lanciaDadi(1).back();
     player.push_back(Giocatore(name, getZone(numZona)));
   }
}

void Board::initalizeMani(){
  if(player.size() == 1){
    nCarte = 6;
  }else if(player.size() == 2){
    nCarte = 5;
  }else if(player.size() == 3){
    nCarte = 5;
  }else if(player.size() == 4){
    nCarte = 4;
  }else if(player.size() == 5){
    nCarte = 3;
  }else{
    initalizeGame();
  }

  for(auto &p : player)
  {
    p.svuotaMano();
    for(int i = 0; i < nCarte; i++)
    {
      p.pescaCarta(mazzoPesca);
    }
  }

  for(int i = 0; i < mazzoPesca.fascisti; i++){
    mazzoPesca.aggiungiFascisti();
  }

  mazzoPesca.shuffle();
}

bool Board::stillAlive(){
  for (const auto& point : pointBoard) {
    if (point.IsCover && point.IsBarricate) {
        return false;
    }
  }

  if(pointBoard.back().IsCover == true){
    return false;
  }

  return true;
}

void Board::drawPointBoard() const {
  int lastCoverIndex = -1;
  for (int i = 0; i < pointBoard.size(); ++i) {
      if (pointBoard[i].IsCover) {
          lastCoverIndex = i;
      }
  }

  // Stampa il board
  for (int i = 0; i < pointBoard.size(); ++i) {
      if (i == lastCoverIndex) {
          std::cout << "[👾]";
      } else if (pointBoard[i].IsBarricate) {
          std::cout << "[#]";
      } else {
          std::cout << "[ ]";
      }
  }
  std::cout << std::endl;
}

void Board::display() const {
  std::cout << "\n\n";
  drawPointBoard();
  std::cout << "\n";
  // Intestazione tabella
  std::cout << "┌────┬────────────────┬────────────┬──────────┬────────────┬───"
               "───────┬──────────┐\n";
  std::cout << "│ #  │ Zona           │ Barricate  │ Fascisti │ Munizioni  │ "
               "Pozioni  │ Civili   │\n";
  std::cout << "├────┼────────────────┼────────────┼──────────┼────────────┼───"
               "───────┼──────────┤\n";

  // Riga dati per ogni zona
  for (const auto &z : zones) {
    const auto &o = z.oggetti;

    std::cout << "│ " << std::right << std::setw(2) << z.number << " │ "
              << std::left << std::setw(14) << z.name << " │ " << std::right
              << std::setw(6) << o.nBarricate << " /" << std::setw(2)
              << o.nMaxBarricate
              << " │ " // Adjusted width and spacing for Barricate
              << std::setw(8) << o.nFascisti
              << " │ " // Keep width 8, right aligned
              << std::setw(10) << o.nMunizioni
              << " │ " // Keep width 10, right aligned
              << std::setw(8) << o.nPozioni
              << " │ " // Keep width 8, right aligned
              << std::setw(8) << o.nCivili
              << " │\n"; // Keep width 8, right aligned
  }

  // Chiusura tabella
  std::cout << "└────┴────────────────┴────────────┴──────────┴────────────┴───"
               "───────┴──────────┘\n";
}