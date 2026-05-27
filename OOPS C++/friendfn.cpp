#include <iostream>
using namespace std;
class BankAccount
{
private:
    double balance;

public:
    BankAccount(double b) : balance(b) {}
    // The 'displayBalance' declared as a friend
    friend void displayBalance(BankAccount account);
};

// This is a NORMAL, non-member function. It is NOT BankAccount::displayBalance
void displayBalance(BankAccount account)
{
    // Because it's a friend, it can directly access the private 'balance' member.
    cout << "The account balance is: " << account.balance << endl;
}

int main()
{
    BankAccount myAccount(1500.75);

    displayBalance(myAccount);

    return 0;
}