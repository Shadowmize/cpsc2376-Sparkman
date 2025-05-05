#include "game.h"

Game::Game(TTF_Font* f) {
    board.resize(9, EMPTY);
    player1Turn = true;
    font = f;
}

void Game::play(int move) {
    if (move >= 0 && move < 9 && board[move] == EMPTY && status() == ONGOING) {
        board[move] = player1Turn ? X : O;
        player1Turn = !player1Turn;
    }
}

bool Game::boardFull() const {
    for (Cell c : board)
        if (c == EMPTY) return false;
    return true;
}

bool Game::checkWin(Cell player) const {
    const int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (auto& p : winPatterns) {
        if (board[p[0]] == player && board[p[1]] == player && board[p[2]] == player)
            return true;
    }
    return false;
}

Status Game::status() const {
    if (checkWin(X)) return PLAYER_1_WINS;
    if (checkWin(O)) return PLAYER_2_WINS;
    if (boardFull()) return DRAW;
    return ONGOING;
}

bool Game::isPlayer1Turn() const {
    return player1Turn;
}

void Game::draw(SDL_Renderer* renderer) {
    int size = 200;
    for (int i = 0; i < 9; ++i) {
        int row = i / 3;
        int col = i % 3;
        SDL_Rect cell = { col * size, row * size, size, size };

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &cell);

        if (board[i] != EMPTY) {
            SDL_Color color = (board[i] == X) ? SDL_Color{ 255, 0, 0, 255 } : SDL_Color{ 0, 0, 255, 255 };
            const char* symbol = (board[i] == X) ? "X" : "O";
            SDL_Surface* surf = TTF_RenderText_Blended(font, symbol, color);
            SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);

            int tw = surf->w, th = surf->h;
            SDL_Rect dst = { cell.x + (size - tw) / 2, cell.y + (size - th) / 2, tw, th };
            SDL_RenderCopy(renderer, tex, nullptr, &dst);

            SDL_FreeSurface(surf);
            SDL_DestroyTexture(tex);
        }
    }

    const char* msg = nullptr;
    if (status() == PLAYER_1_WINS) msg = "Player X Wins!";
    else if (status() == PLAYER_2_WINS) msg = "Player O Wins!";
    else if (status() == DRAW) msg = "It's a Draw!";

    if (msg) {
        SDL_Color white = { 255, 255, 255, 255 };
        SDL_Surface* surf = TTF_RenderText_Blended(font, msg, white);
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);

        SDL_Rect dst = { 100, 620, surf->w, surf->h };
        SDL_RenderCopy(renderer, tex, nullptr, &dst);

        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
    }
}
