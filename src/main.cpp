#include "Board.h"
#include <chrono>
#include <thread>
#include <iostream>


int main() {

  const int MAX_GIORNATE = 5;

  // Inizializza il generatore di numeri casuali
  srand(static_cast<unsigned int>(time(0)));

  Board board;
  board.initalizeGame();   

  // Aggiungo oggetti e fascisti
  board.initalizeGame();

  // MAIN LOOP 
  while (board.stillAlive() && board.getGiorno() < MAX_GIORNATE) {
    for(int i = 0; i < board.getNumPlayers(); i++){
      Giocatore pl = board.getPlayer(i);

      // 1) Il Giocatore può spostarsi
      std::cout << "\nTurno di " << pl.getNome() << std::endl;
      board.display();
      pl.mostraStato();
      std::cout << "Vuoi spostarti di zona? (s/n) ";
      char scelta; std::cin >> scelta;
      if (scelta == 's' || scelta == 'S') {
          int nuovaZona;
          std::cout << "Inserisci il numero della zona: ";
          std::cin >> nuovaZona;
          // TODO: verifica coerenza mappa, oggetto trasportabile, ecc.
          pl.setZona(nuovaZona);
      }

      // 2) Gioca carte per tirare i dadi
      std::cout << "Quante carte uguali vuoi giocare? ";
      int nCarteUguali; std::cin >> nCarteUguali;
      // TODO: chiedi al giocatore quali carte, controlla che ne abbia...
      for (int k = 0; k < nCarteUguali; ++k) {
          // TODO: pl.giocaCarta(nomeCarta);
      }

      // 3) Lancia i dadi
      std::vector<int> risultati = board.lanciaDadi(nCarteUguali);
      std::cout << "Risultati dadi: ";
      for (int d : risultati) std::cout << d << ' ';
        std::cout << std::endl;

      // 4) gestisci creazione degli oggetti (munizioni, pozioni, civili, barricate)

      // 5) Pesca fino ad avere di nuovo N carte in mano
      
      // 6) Dopo l’azione può spostarsi di nuovo (opzionale)
      std::cout << "Vuoi spostarti di nuovo? (s/n) ";
      std::cin >> scelta;
      if (scelta == 's' || scelta == 'S') {
          int nuovaZona;
          std::cout << "Inserisci il numero della zona (stessa mappa): ";
          std::cin >> nuovaZona;
          pl.setZona(nuovaZona);
      }

      // 7) controllo se non si ha perso
      if (!board.stillAlive()) break;
    }

  // A questo punto, se il mazzo era vuoto, mazzoPesca.pescaCarta() ha già:
  //   1) incrementato nGiornata interno al Mazzo
  //   2) mescolato di nuovo
  //   3) aggiunto i fascisti in più
  // Possiamo anche sincronizzare giorno su Board:
  // TODO: board.setGiorno( mazzoPesca.getFascisti() );
}

  return 0;
}
