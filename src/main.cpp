#include "Board.h"
#include <chrono>
#include <thread>
#include <iostream>

std::vector<int> lanciaDadi(int numDadi) {
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

void initalizeGame(Board& board){
  // Inserisco nelle zone gli oggetti ed i fasci
  std::vector<int> risultati;

  // Aggiungo i fascisti
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
    board.aggiungiFascistaAZona(risultati[i]);
  }

  // Aggiungo le munizioni
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
    board.aggiungiMunizioneAZona(risultati[i]);
  }

  // Aggiungo le pozioni
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
    board.aggiungiPozioneAZona(risultati[i]);
  }

  // Aggiungo i civili
  risultati = lanciaDadi(2);
  for (int i = 0; i < risultati.size(); i++) {
    board.aggiungiCivileAZona(risultati[i]);
  }

}

int main() {
  Board board;
  std::vector<int> risultati;

  // Inizializza il generatore di numeri casuali
  srand(static_cast<unsigned int>(time(0)));

  // Stampa lo stato corrente
  board.display();

  // Aggiungo oggetti e fascisti
  initalizeGame(board);

  // Stampa lo stato corrente
  board.display();

  // Piccola pausa prima di chiudere (solo per console)
  std::this_thread::sleep_for(std::chrono::seconds(5));
  return 0;
}
