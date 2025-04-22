// Board.cpp
#include "Board.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

Board::Board() {
  // Configurazione iniziale: nomi e livello max
  zones.emplace_back("Naviglio", 1);
  zones.emplace_back("Naviglio", 2);
  zones.emplace_back("Naviglio", 3);
  zones.emplace_back("Naviglio", 4);
  zones.emplace_back("Oltretorrente", 5);
  zones.emplace_back("Oltretorrente", 6);

  carte.Mazzo_Default();
}

Zone &Board::getZone(const int &nZone) {
  auto it = std::find_if(zones.begin(), zones.end(),
                         [&](const Zone &z) { return z.number == nZone; });
  if (it == zones.end())
    throw std::runtime_error("Zona non trovata");
  return *it;
}

bool Board::aggiungiFascistaAZona(int numeroZona) {
  if (risorseGlobali.usaFascista()) {
    getZone(numeroZona).oggetti.Add_Fascisti();
    return true;
  }
  return false;
}

bool Board::aggiungiBarricataAZona(int numeroZona) {
  if (risorseGlobali.usaBarricata()) {
    getZone(numeroZona).oggetti.Add_Barricata();
    return true;
  }
  return false;
}

bool Board::aggiungiMunizioneAZona(int numeroZona) {
  if (risorseGlobali.usaMunizione()) {
    getZone(numeroZona).oggetti.Add_Munizioni();
    return true;
  }
  return false;
}

bool Board::aggiungiPozioneAZona(int numeroZona) {
  if (risorseGlobali.usaPozione()) {
    getZone(numeroZona).oggetti.Add_Pozioni();
    return true;
  }
  return false;
}

bool Board::aggiungiCivileAZona(int numeroZona) {
  if (risorseGlobali.usaCivile()) {
    getZone(numeroZona).oggetti.Add_Civili();
    return true;
  }
  return false;
}

bool Board::rimuoviFascistaDaZona(int numeroZona) {
  getZone(numeroZona).oggetti.Remove_Fascisti();
  risorseGlobali.fascistiDisponibili++;
  return true;
}

bool Board::rimuoviMunizioneDaZona(int numeroZona) {
  getZone(numeroZona).oggetti.Remove_Munizioni();
  risorseGlobali.munizioniDisponibili++;
  return true;
}

bool Board::rimuoviPozioneDaZona(int numeroZona) {
  getZone(numeroZona).oggetti.Remove_Pozioni();
  risorseGlobali.pozioniDisponibili++;
  return true;
}

bool Board::rimuoviCivileDaZona(int numeroZona) {
  getZone(numeroZona).oggetti.Remove_Civili();
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
  carte.mostraCarte();
}

void Board::initalizeGame(){
  // Inserisco nelle zone gli oggetti ed i fasci
  std::vector<int> risultati;

  // Aggiungo i fascisti
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
    aggiungiFascistaAZona(risultati[i]);
  }

  // Aggiungo le munizioni
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
    aggiungiMunizioneAZona(risultati[i]);
  }

  // Aggiungo le pozioni
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
   aggiungiPozioneAZona(risultati[i]);
  }

  // Aggiungo i civili
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
    aggiungiCivileAZona(risultati[i]);
  }

  // Inserisci numero player
  int nPlayer = 0;
  std::cout << "inserisci il numero di giocatori: ";
  std::cin >> nPlayer;

  for(int i = 0; i < nPlayer; i++)
  {
    player.push_back(Giocatore("aaa", lanciaDadi(1).back()));
  }

  for(int i = 0; i < player.size() i++)
  {
    player.mostraStato();
  }

}

void Board::display() const {
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