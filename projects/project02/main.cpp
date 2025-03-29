//used ghatgpt to assist
#include <iostream>
#include "game.h"

int main() {
    Game game;
    int move;
    while (game.status() == ONGOING) {
        std::cout << game;
        if (game.isPlayer1Turn()) {
            std::cout << "Player X enter your move 0-8: ";
        }
        else {
            std::cout << "Player O enter your move 0-8: ";
        }
        std::cin >> move;
        game.play(move);
        if (game.status() == PLAYER_1_WINS) {
            std::cout << game;
            std::cout << "Player X wins\n";
        }
        else if (game.status() == PLAYER_2_WINS) {
            std::cout << game;
            std::cout << "Player O wins\n";
        }
        else if (game.status() == DRAW) {
            std::cout << game;
            std::cout << "It's a draw\n";
        }
    }
    return 0;
}