//used to chatgpt to assist

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>

enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum Cell { EMPTY, X, O };

class Game {
private:
    std::vector<Cell> board;
    bool player1Turn;
    bool checkWin(Cell player) const;
    bool boardFull() const;

public:
    Game();
    void play(int move);
    Status status() const;
    void display() const;
    bool isPlayer1Turn() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif