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
            Oggetti oggetti = board.getOggettiInZona(board.getZone(pl.getZona()));
            int nuovaZona;
            std::cout << "Inserisci il numero della zona: ";
            std::cin >> nuovaZona;
            nuovaZona--;
            pl.spostaConOggetto(oggetti, board.getZone(nuovaZona));
          }else{
            int nuovaZona;
            std::cout << "Inserisci il numero della zona: ";
            std::cin >> nuovaZona;
            nuovaZona--;
            pl.setZona(board.getZone(nuovaZona));
          } 

          board.MostraZonaGiocatore(pl.getZona());
          system("pause");
      }

      // 2) Gioca carte per tirare i dadi
      int nCarteUguali = 0;
      std::string nomeCarta = "";

      do{
        std::cout << "Quale azione vuoi compiere? ";
        pl.mostraAzioni();
        std::cin >> nomeCarta;

        std::cout << "Quante carte vuoi giocare? ";
        std::cin >> nCarteUguali;
       
      }while(!pl.giocaCarta(nomeCarta, nCarteUguali) && ((nomeCarta[0] == 's' || 'S') && board.getZone(pl.getZona()).oggetti.nMunizioni > 0) ? true : false); // finchè non ha carte valide
      

      // 3) Lancia i dadi
      std::vector<int> risultati = board.lanciaDadi(nCarteUguali);

      int somma = 0;
      for (int i = 0; i < risultati.size(); i++) {
        somma += risultati[i];
      }

      std::cout << "Risultati dadi: " << somma << std::endl;
      
      switch(nomeCarta[0]){
        case 'S':
          std::cout << "Hai sparato " << somma / 5 << " Colpi" << std::endl;
          for(int i = 0; i < (somma / 5); i++)
            board.rimuoviFascistaDaZona(board.getZone(pl.getZona()));
          break;
        case 'M':
          std::cout << "Hai creato " << somma / 5 << " Munizioni" << std::endl;
          for(int i = 0; i < (somma / 5); i++)
            board.aggiungiMunizioneAZona(board.getZone(pl.getZona()));
          break;
        case 'P':
         std::cout << "Hai creato " << somma / 5 << " Pozioni" << std::endl;
          for(int i = 0; i < (somma / 5); i++)
            board.aggiungiPozioneAZona(board.getZone(pl.getZona()));
          break;
        case 'C':
          std::cout << "Hai creato " << somma / 5 << " Civili" << std::endl;
          for(int i = 0; i < (somma / 5); i++)
            board.aggiungiCivileAZona(board.getZone(pl.getZona()));
          break;
        case 'B':
          if(somma >= board.getPunteggioBarricata()){
            std::cout << "Hai posizionato una Barricata" << std::endl;
            board.aggiungiBarricataAZona(board.getZone(pl.getZona()));
          }
          break;
        default:
          std::cout << "Carta non valida" << std::endl;
          break;
      }

      board.MostraZonaGiocatore(pl.getZona());

      // 5) Dopo l’azione può spostarsi di nuovo (opzionale)
      if(!pl.spostato){
        std::cout << "Vuoi spostarti di zona? (s/n) ";
        char scelta; std::cin >> scelta;

        if (scelta == 's' || scelta == 'S') {
          pl.spostato = true;
            std::cout << "Vuoi spostarti con un oggetto?: ";
            std::cin >> scelta;
            if (scelta == 's' || scelta == 'S'){
              Oggetti oggetti = board.getOggettiInZona(board.getZone(pl.getZona()));
              int nuovaZona;
              nuovaZona--;
              std::cout << "Inserisci il numero della zona: ";
              std::cin >> nuovaZona;
              pl.spostaConOggetto(oggetti, board.getZone(nuovaZona));
            }else{
              int nuovaZona;
              std::cout << "Inserisci il numero della zona: ";
              std::cin >> nuovaZona;
              nuovaZona--;
              pl.setZona(board.getZone(nuovaZona));
            } 
        }
      }

      // 6) Pesca fino ad avere di nuovo N carte in mano
      
     
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


