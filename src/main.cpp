#include "Board.h"
#include <thread>
#include <chrono>

int main() {
    Board board;
    
    // Stampa lo stato corrente
    board.display();

    // Piccola pausa prima di chiudere (solo per console)
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}
