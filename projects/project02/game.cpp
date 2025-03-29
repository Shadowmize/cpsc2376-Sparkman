//used chatgpt to assist
#include "game.h"

Game::Game() {
    board.resize(9, EMPTY);
    player1Turn = true;
}

void Game::play(int move) {
    if (move >= 0 && move < 9) {
        if (board[move] == EMPTY) {
            if (player1Turn) {
                board[move] = X;
            }
            else {
                board[move] = O;
            }
            player1Turn = !player1Turn;
        }
    }
}

bool Game::boardFull() const {
    for (int i = 0; i < 9; i++) {
        if (board[i] == EMPTY) {
            return false;
        }
    }
    return true;
}

bool Game::checkWin(Cell player) const {
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == player && board[wins[i][1]] == player && board[wins[i][2]] == player) {
            return true;
        }
    }
    return false;
}

Status Game::status() const {
    if (checkWin(X)) {
        return PLAYER_1_WINS;
    }
    if (checkWin(O)) {
        return PLAYER_2_WINS;
    }
    if (boardFull()) {
        return DRAW;
    }
    return ONGOING;
}

bool Game::isPlayer1Turn() const {
    return player1Turn;
}

void Game::display() const {
    for (int i = 0; i < 9; i++) {
        if (board[i] == X) {
            std::cout << "X";
        }
        else if (board[i] == O) {
            std::cout << "O";
        }
        else {
            std::cout << i;
        }
        if ((i + 1) % 3 == 0) {
            std::cout << "\n";
        }
        else {
            std::cout << "|";
        }
    }
    std::cout << "\n";
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    game.display();
    return os;
}
