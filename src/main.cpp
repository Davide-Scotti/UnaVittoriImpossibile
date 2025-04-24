#include "Board.h"
#include <chrono>
#include <thread>
#include <iostream>

// comando console: [Console]::OutputEncoding = [System.Text.Encoding]::UTF8

int main() {

  const int MAX_GIORNATE = 5;

  // Inizializza il generatore di numeri casuali
  srand(static_cast<unsigned int>(time(0)));

  Board board;
  Mazzo mazzo;

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
        pl.spostato = true;
          std::cout << "Vuoi spostarti con un oggetto?: ";
          std::cin >> scelta;
          if (scelta == 's' || scelta == 'S'){
            Oggetti oggetti = board.getOggettiInZona(pl.getZona());
            int nuovaZona;
            std::cout << "Inserisci il numero della zona: ";
            std::cin >> nuovaZona;
            pl.spostaConOggetto(oggetti, board.getZone(nuovaZona));
          }else{
            int nuovaZona;
            std::cout << "Inserisci il numero della zona: ";
            std::cin >> nuovaZona;
            pl.setZona(board.getZone(nuovaZona));
          } 
      }

      // 2) Gioca carte per tirare i dadi
      int nCarteUguali = 0;
      std::string nomeCarta = "";

      std::cout << "Quale azione vuoi compiere? ";
      pl.mostraAzioni();
      std::cin >> nomeCarta;

      std::cout << "Quante carte vuoi giocare? ";
      std::cin >> nCarteUguali;+
      pl.giocaCarta(nomeCarta, nCarteUguali);

      // 3) Lancia i dadi
      std::vector<int> risultati = board.lanciaDadi(nCarteUguali);
      std::cout << "Risultati dadi: ";
      // TODO: Inserisci pedine sulla board in base al numero di dadi lanciati
 
      // 4) gestisci creazione degli oggetti (munizioni, pozioni, civili, barricate)

      // 5) Pesca fino ad avere di nuovo N carte in mano
      
      // 6) Dopo l’azione può spostarsi di nuovo (opzionale)
      if(!pl.spostato){
        std::cout << "Vuoi spostarti di zona? (s/n) ";
        char scelta; std::cin >> scelta;

        if (scelta == 's' || scelta == 'S') {
          pl.spostato = true;
            std::cout << "Vuoi spostarti con un oggetto?: ";
            std::cin >> scelta;
            if (scelta == 's' || scelta == 'S'){
              Oggetti oggetti = board.getOggettiInZona(pl.getZona());
              int nuovaZona;
              std::cout << "Inserisci il numero della zona: ";
              std::cin >> nuovaZona;
              pl.spostaConOggetto(oggetti, board.getZone(nuovaZona));
            }else{
              int nuovaZona;
              std::cout << "Inserisci il numero della zona: ";
              std::cin >> nuovaZona;
              pl.setZona(board.getZone(nuovaZona));
            } 
        }
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
