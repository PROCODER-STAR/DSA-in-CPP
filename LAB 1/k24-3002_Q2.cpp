#include <iostream>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    double* balance;

public:
    BankAccount(double initial_balance = 0.0) {
        balance = new double(initial_balance);  
        cout << "Account created with balance: " << *balance << endl;
    }

    BankAccount(const BankAccount& other) {
        balance = new double(*(other.balance)); 
        cout << "Account copied with balance: " << *balance << endl;
    }

    BankAccount& operator=(const BankAccount& other) {
        if (this == &other) 
            return *this;
        
        delete balance; 

        balance = new double(*(other.balance));
        cout << "Account assigned with balance: " << *balance << endl;
        
        return *this;
    }

    ~BankAccount() {
        delete balance;
        cout << "Account destroyed" << endl;
    }

    void withdraw(double amount) {
        if (amount > *balance) {
            cout << "Insufficient funds. Current balance: " << *balance << endl;
        } else {
            *balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << *balance << endl;
        }
    }

    void displayBalance() const {
        cout << "Current balance: " << *balance << endl;
    }
};

int main() {
    BankAccount account1(500.0);

    BankAccount account2 = account1;

    account2.withdraw(200.0);

    cout << "After withdrawal from account2:\n";
    cout << "account1: ";
    account1.displayBalance();
    cout << "account2: ";
    account2.displayBalance();

    return 0;
}
