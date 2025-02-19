//used chat gpt to help with this one to
#include <iostream>
#include <deque>
#include <string>

class UndoableTextEditor {
private:
    std::deque<std::string> history;
    std::string text;

public:
    void addText(const std::string& newText) {
        history.push_back(text); 
        if (!text.empty()) text += " ";
        text += newText;
    }

    void undo() {
        if (!history.empty()) {
            text = history.back();
            history.pop_back();
            std::cout << "Undo successful!" << std::endl;
        }
        else {
            std::cout << "Nothing to undo!" << std::endl;
        }
    }

    void show() const {
        std::cout << "Current Content: " << text << std::endl;
    }
};

int main() {
    UndoableTextEditor editor;
    int choice;
    std::string input;

    while (true) {
        std::cout << "\n1. Add Text" << std::endl;
        std::cout << "2. Undo" << std::endl;
        std::cout << "3. Show Content" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            std::cout << "Enter text: ";
            std::getline(std::cin, input);
            editor.addText(input);
            break;
        case 2:
            editor.undo();
            break;
        case 3:
            editor.show();
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice! Try again." << std::endl;
        }
    }
}