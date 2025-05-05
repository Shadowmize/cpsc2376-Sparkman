#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

enum Cell { EMPTY, X, O };
enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

class Game {
private:
    std::vector<Cell> board;
    bool player1Turn;
    TTF_Font* font;

    bool checkWin(Cell player) const;
    bool boardFull() const;

public:
    Game(TTF_Font* font);
    void play(int move);
    Status status() const;
    bool isPlayer1Turn() const;
    void draw(SDL_Renderer* renderer);
};

#endif
