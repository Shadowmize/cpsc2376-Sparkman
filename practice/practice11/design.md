//USED CHATGPT  TO ASSIST





NOUNS
BoardGame
Customer
LoanRecord
Name
ID
Copies
DueDate


THINGS IT SHOULD DO
list all games
check out a game
return a game
view who's borrowing what
add new games

class BoardGame {
private:
    int gameID;
    std::string name;
    int totalCopies;
    int copiesAvailable;

public:
    BoardGame(int id, std::string name, int total);

    int getGameID() const;
    std::string getName() const;
    int getAvailableCopies() const;

    void checkoutCopy();
    void returnCopy();
};


Class Customer

class Customer {
private:
    int customerID;
    std::string name;

public:
    Customer(int id, std::string name);

    int getCustomerID() const;
    std::string getName() const;
};

class LoanRecord {
private:
    int recordID;
    BoardGame* game;
    Customer* customer;
    std::string dueDate;

public:
    LoanRecord(int id, BoardGame* game, Customer* customer, std::string dueDate);

    int getRecordID() const;
    BoardGame* getGame() const;
    Customer* getCustomer() const;
    std::string getDueDate() const;

    void returnGame();
};


classDiagram
    class BoardGame {
        
int gameID
string name
int totalCopies
int copiesAvailable+ BoardGame(int, string, int)+ int getGameID()+ string getName()+ int getAvailableCopies()+ void checkoutCopy()+ void returnCopy()
}

    class Customer {
        
int customerID
string name+ Customer(int, string)+ int getCustomerID()+ string getName()}

    class LoanRecord {
        
int recordID
BoardGame* game
Customer* customer
string dueDate+ LoanRecord(int, BoardGame, Customer, string)+ int getRecordID()+ BoardGame* getGame()+ Customer* getCustomer()+ string getDueDate()+ void returnGame()
}

    LoanRecord --> BoardGame : "borrows"
    LoanRecord --> Customer : "borrowed by"
