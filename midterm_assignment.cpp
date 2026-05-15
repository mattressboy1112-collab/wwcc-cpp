#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

struct Transaction {
    string type; // "deposit", "withdrawl", "transfer"
    double amount;
    time_t date;
};

struct Account {
    int accountNumber;
    string holderName;
    double balance;
    Transaction history[100] = {};
    int transactionCount = 0;
};

void CreateAccount(vector<Account>& lst, int& counter, string name, double start_cash = 0) {
    Account temp1;
    temp1.accountNumber = counter;
    counter++;
    temp1.holderName = name;
    temp1.balance = start_cash;
    lst.push_back(temp1);
}

void AddOrRemoveMoney(Account& ac1, double change, string transaction_type) {
    ac1.transactionCount++;
    ac1.balance += change;
    for (int i = ac1.transactionCount-1; i > 0; i--) {
        ac1.history[i] = ac1.history[i-1]; 
    }
    Transaction& hist1 = ac1.history[0];
    hist1.amount = change;
    hist1.type = transaction_type;
    time(&hist1.date);
}

int main() {
    int counter = 0;
    vector<Account> accounts = {};
    int input = -1;
    cout << "--------------" << endl;
    cout << "Bad Banking!" << endl;
    while (not(input == 0)) {
        cout << "--------------" << endl;
        cout << "Input operation:" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Create new account" << endl;
        cout << "2 - Print all accounts" << endl;
        cout << "3 - Deposit money into account" << endl;
        cout << "4 - Withdrawl money from an account" << endl;
        cout << "5 - Transfer money between accounts" << endl;
        cout << "6 - Print transaction history" << endl;
        cout << "- "; cin >> input;
        if (not(input == 0)) {
            cout << "--------------" << endl;
            if (input == 1) {
                string temp;
                double start_amount = 0;
                cout << "Name: "; cin >> temp;
                cout << "Starting amount: "; cin >> start_amount;
                CreateAccount(accounts, counter, temp, start_amount);
            } else if (input == 2) {
                for (Account acc : accounts) {
                    cout << acc.accountNumber << "-" << acc.holderName << " - " << acc.balance << endl;
                }
            } else if (input == 3) {
                int acc_num;
                double money;
                cout << "What is the account ID?" << endl;
                cout << "- "; cin >> acc_num;
                if (acc_num > -1 and acc_num < int(accounts.size())) {
                    cout << "How much is being added?" << endl;
                    cout << "- "; cin >> money;
                    Account& acc = accounts[acc_num];
                    AddOrRemoveMoney(acc, money, "deposit");
                    cout << endl << "Added " << money << " to account " << acc.accountNumber << "-" << acc.holderName << endl;
                } else {
                    cout << endl << "Invalid user ID - returning to menu" << endl;
                }
            } else if (input == 4) {
                int acc_num;
                double money;
                cout << "What is the account ID?" << endl;
                cout << "- "; cin >> acc_num;
                if (acc_num > -1 and acc_num < int(accounts.size())) {
                    cout << "How much is being withdrawn?" << endl;
                    cout << "- "; cin >> money;
                    Account& acc = accounts[acc_num];
                    AddOrRemoveMoney(acc, -money, "withdrawl");
                    cout << endl << "Withdrawn " << money << " from account " << acc.accountNumber << "-" << acc.holderName << endl;
                } else {
                    cout << endl << "Invalid user ID - returning to menu" << endl;
                }
            } else if (input == 5) {
                int acc_num1, acc_num2;
                double money;
                cout << "What is the account ID? - One to be taken from." << endl;
                cout << "- "; cin >> acc_num1;
                if (acc_num1 > -1 and acc_num1 < int(accounts.size())) {
                    cout << "What is the account ID? - One to be added to." << endl;
                    cout << "- "; cin >> acc_num2;
                    if (acc_num2 > -1 and acc_num2 < int(accounts.size())) {
                        cout << "How much is being transfered?" << endl;
                        cout << "- "; cin >> money;
                        Account& acc1 = accounts[acc_num1];
                        AddOrRemoveMoney(acc1, -money, "transfer");
                        Account& acc2 = accounts[acc_num2];
                        AddOrRemoveMoney(acc2, money, "transfer");
                        cout << endl << "Transfered " << money << " from account " << acc1.accountNumber << "-" << acc1.holderName << " to account " << acc2.accountNumber << "-" << acc2.holderName << endl;
                    } else {
                        cout << endl << "Invalid user ID - returning to menu" << endl;
                    }
                } else {
                    cout << endl << "Invalid user ID - returning to menu" << endl;
                }
            } else if (input == 6) {
                int acc_num;
                cout << "What is the account ID?" << endl;
                cout << "- "; cin >> acc_num;
                if (acc_num > -1 and acc_num < int(accounts.size())) {
                    Account& acc = accounts[acc_num];
                    cout << acc.transactionCount << " total transactions (100 max shown)" << endl;
                    const int MAX_TRANSACTIONS = 100;
                    for (int i = 0; (i < acc.transactionCount) and (i < MAX_TRANSACTIONS-1); i++) { 
                        Transaction h = acc.history[i];
                        cout << ctime(&h.date) << h.type << " - " << h.amount << endl;
                    }
                } else {
                    cout << endl << "Invalid user ID - returning to menu" << endl;
                }
            }
        } else {
            cout << "--------------";
            cout << "Goodbye!";
        }
    }
    return 0;
}