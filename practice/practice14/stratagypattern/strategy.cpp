#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class TextThing {
public:
    virtual std::string go(std::string txt) = 0;
    virtual ~TextThing() {}
};

class Reverse : public TextThing {
public:
    std::string go(std::string txt) override {
        return std::string(txt.rbegin(), txt.rend());
    }
};

class BigLetters : public TextThing {
public:
    std::string go(std::string txt) override {
        for (char& c : txt) {
            c = toupper(c);
        }
        return txt;
    }
};

class NoVowels : public TextThing {
public:
    std::string go(std::string txt) override {
        std::string r = "";
        for (char c : txt) {
            if (std::string("aeiouAEIOU").find(c) == std::string::npos) {
                r += c;
            }
        }
        return r;
    }
};

class BadWords : public TextThing {
public:
    std::string go(std::string txt) override {
        std::vector<std::string> bad = { "bad", "ugly" };
        for (std::string b : bad) {
            size_t spot = txt.find(b);
            while (spot != std::string::npos) {
                txt.replace(spot, b.size(), std::string(b.size(), '*'));
                spot = txt.find(b);
            }
        }
        return txt;
    }
};

int main() {
    std::string stuff;
    std::cout << "Type something: ";
    std::getline(std::cin, stuff);

    std::unique_ptr<TextThing> strat;

    while (true) {
        std::cout << "\n1. Reverse\n2. All Caps\n3. Remove vowels\n4. Censor bad stuff\n5. Quit\nPick one: ";
        int x;
        std::cin >> x;
        std::cin.ignore();

        if (x == 1)
            strat = std::make_unique<Reverse>();
        else if (x == 2)
            strat = std::make_unique<BigLetters>();
        else if (x == 3)
            strat = std::make_unique<NoVowels>();
        else if (x == 4)
            strat = std::make_unique<BadWords>();
        else if (x == 5)
            break;
        else {
            std::cout << "nah try again\n";
            continue;
        }

        std::cout << "Result: " << strat->go(stuff) << "\n";
    }

    return 0;
}