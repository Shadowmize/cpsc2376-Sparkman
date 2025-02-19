// used chatgpt to help with making the user input accept lower case and uppercase then used it to help lable the grids and got it to help toggle lights off and on
enum GameState { ONGOING, WIN };
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>

enum GameState { ONGOING, WIN };

class LightsOut {
private:
    static const int SIZE = 5;
    std::vector<std::vector<bool>> board;

public:
    LightsOut() {
        makeBoard();
    }
    
    void makeBoard() {
        board = std::vector<std::vector<bool>>(SIZE, std::vector<bool>(SIZE, true));
    }
    
    void printBoard() {
        std::cout << "\n  ";
        for (int j = 0; j < SIZE; j++) {
            std::cout << (char)('A' + j) << " ";
        }
        std::cout << "\n";
        
        for (int i = 0; i < SIZE; i++) {
            std::cout << (char)('F' + i) << " ";
            for (int j = 0; j < SIZE; j++) {
                std::cout << (board[i][j] ? "O " : "X ");
            }
            std::cout << "\n";
        }
    }
    
    void toggle(int x, int y) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            board[x][y] = !board[x][y];
        }
    }
    
    void play(int x, int y) {
        toggle(x, y);
        toggle(x - 1, y);
        toggle(x + 1, y);
        toggle(x, y - 1);
        toggle(x, y + 1);
    }
    
    int gameStatus() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j]) {
                    return ONGOING;
                }
            }
        }
        return WIN;
    }
    
    void rules() {
        std::cout << "Welcome to Lights Out!\n";
        std::cout << "Turn off all the lights to win.\n";
        std::cout << "Pick a spot (like F A or A F) to flip it and the ones next to it.\n";
        std::cout << "If you turn them all off, you win!\n";
    }
};

bool parseInput(std::string input, int &x, int &y) {
    std::istringstream iss(input);
    char first, second;
    if (!(iss >> first >> second)) return false;
    
    first = toupper(first);
    second = toupper(second);
    
    if (first >= 'F' && first < 'F' + 5 && second >= 'A' && second < 'A' + 5) {
        x = first - 'F';
        y = second - 'A';
    } else if (first >= 'A' && first < 'A' + 5 && second >= 'F' && second < 'F' + 5) {
        x = second - 'F';
        y = first - 'A';
    } else {
        return false;
    }
    
    return true;
}

int main() {
    srand(time(0));
    LightsOut game;
    game.rules();
    
    while (true) {
        game.printBoard();
        std::string input;
        std::cout << "Enter row and column (like F A or A F) or X to exit: ";
        std::getline(std::cin, input);
        
        if (input == "X" || input == "x") break;
        
        int x, y;
        if (!parseInput(input, x, y)) {
            std::cout << "Try again with the right format.\n";
            continue;
        }
        
        game.play(x, y);
        
        if (game.gameStatus() == WIN) {
            game.printBoard();
            std::cout << "You Win!\n";
            break;
        }
    }
    return 0;
}
