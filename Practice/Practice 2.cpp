// used chatgpt to make the menu and then used it to make the skeleton of the switch statment


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILE_NAME = "account_balance.txt"; 


double readBalanceFromFile(); 
void writeBalanceToFile(double balance); 
void checkBalance(double balance); 
void deposit(double& balance); 
void withdraw(double& balance); 

int main() {
    double balance = readBalanceFromFile(); 

    cout << "Hey, welcome to your bank!" << endl; 

    int choice;
    do {
        
        cout << "\nWhat do you wanna do?" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Pick an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            checkBalance(balance); 
            break;
        case 2:
            deposit(balance); 
            break;
        case 3:
            withdraw(balance); 
            break;
        case 4:
            cout << "Later!" << endl; 
            break;
        default:
            cout << "Uh, try again?" << endl; 
        }
    } while (choice != 4); 

    return 0;
}


double readBalanceFromFile() {
    ifstream file(FILE_NAME);
    double balance;
    if (file) {
        file >> balance; 
        file.close();
    }
    else {
       
        cout << "Oops, no account found. Starting with $100." << endl;
        balance = 100.00;
        writeBalanceToFile(balance);
    }
    return balance;
}


void writeBalanceToFile(double balance) {
    ofstream file(FILE_NAME);
    if (!file) {
        cerr << "Yikes! Can't open file." << endl;
        exit(1); 
    }
    file << fixed << setprecision(2) << balance; 
    file.close();
}


void checkBalance(double balance) {
    cout << "You got: $" << fixed << setprecision(2) << balance << endl; 
}


void deposit(double& balance) {
    double amount;
    cout << "How much you wanna put in? ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Dude, you gotta put a positive number." << endl; 
        return;
    }
    balance += amount; 
    writeBalanceToFile(balance); 
    cout << "Sweet! New balance: $" << fixed << setprecision(2) << balance << endl;
}


void withdraw(double& balance) {
    double amount;
    cout << "How much you wanna take out? ";
    cin >> amount;
    if (amount <= 0) {
        cout << "C'mon, needs to be positive." << endl; 
        return;
    }
    if (amount > balance) {
        cout << "Not enough cash! You only got $" << fixed << setprecision(2) << balance << endl; 
        return;
    }
    balance -= amount; 
    writeBalanceToFile(balance); 
    cout << "Got it! New balance: $" << fixed << setprecision(2) << balance << endl;
}
