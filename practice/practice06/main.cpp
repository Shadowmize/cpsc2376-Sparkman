//used chatgpt to assit
#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

using namespace std;

void menu() {
    cout << "\n1. enter fraction\n2. add\n3. subtract\n4. multiply\n5. divide\n6. show mixed fraction\n7. clear\n8. quit\n";
}

Fraction getFraction() {
    int n, d;
    cout << "enter numerator: ";
    cin >> n;
    cout << "enter denominator: ";
    cin >> d;
    return Fraction(n, d);
}

int main() {
    Fraction current;
    int choice;

    while (true) {
        cout << "\ncurrent: " << current << endl;
        menu();
        cout << "choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                current = getFraction();
            }
            else if (choice >= 2 && choice <= 5) {
                Fraction input = getFraction();
                if (choice == 2) current = current + input;
                if (choice == 3) current = current - input;
                if (choice == 4) current = current * input;
                if (choice == 5) current = current / input;
            }
            else if (choice == 6) {
                MixedFraction mixed(current.getNumerator() / current.getDenominator(), current.getNumerator() % current.getDenominator(), current.getDenominator());
                cout << "mixed: " << mixed << endl;
            }
            else if (choice == 7) {
                current = Fraction(0, 1);
            }
            else if (choice == 8) {
                cout << "bye!\n";
                break;
            }
            else {
                cout << "invalid choice\n";
            }
        }
        catch (const exception& e) {
            cout << "error: " << e.what() << endl;
        }
    }
    return 0;
}
