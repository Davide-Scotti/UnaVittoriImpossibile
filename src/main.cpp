#include "Board.h"
#include <chrono>
#include <thread>
#include <iostream>


int main() {
  Board board;
  Mazzo mazzo;

  // Inizializza il generatore di numeri casuali
  srand(static_cast<unsigned int>(time(0)));

  // Aggiungo oggetti e fascisti
  board.initalizeGame();

  // Piccola pausa prima di chiudere (solo per console)
  system("pause");
  return 0;
}
