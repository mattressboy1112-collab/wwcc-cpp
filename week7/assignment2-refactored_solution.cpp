#include <iostream>
using namespace std; //so that we can actually just say string for variables

double const SAVINGS_INTEREST = 1.03; // made the interest rates constants
double const CHECKING_INTEREST = 1.01;
double const BUSINESS_INTEREST = 1.005;

class Account { // capitalized class name to fit format standards
private: //made the data private
    string customer_name;
    double money;
    bool open;
    int acc_number;
    string type;
public:
    Account(string name, int acc_num, string typ) { // changed variable names to be more descriptive and made the setup function into the constructor
        customer_name = name;
        money = 0;
        open = true;
        acc_number = acc_num;
        if ((typ == "savings") or (typ == "checking") or (typ == "business")) {
            type = typ;
        } else { // validation and failsafe
            cout << endl << "Invalid type, type defaulted to checking" << endl;
            type = "checking";
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            money = money + amount; //checking if money amount is valid
        } else {
            cout << endl << "Invalid deposit: number negative or zero" << endl;
        }
    }

    void withdraw(double amount) { // changed x in both withdraw and deposit to be called amount instead
        if (amount <= money) {
            if (amount > 0) {
                money = money - amount;
            } else {
                cout << endl << "Invalid withdrawl: number negative or zero" << endl; //checking if money amount is valid
            }
        } else {
            cout << endl << "Invalid withdrawl: number exceeds amount in account" << endl;
        }
    }

    void applyInterest() { // Name changed to regular function format and changed "do" to "apply" 
        if (type == "savings") {
            money = money * SAVINGS_INTEREST;
        } else if (type == "checking") {
            money = money * CHECKING_INTEREST;
        } else if (type == "business") {
            money = money * BUSINESS_INTEREST;
        }
    }

    void print() {
        cout << "Account Number: " << acc_number << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Balance: $" << money << endl;
        cout << "Account Type: " << type << endl;
        cout << "Status: " << (open ? "Open" : "Closed") << endl;
    }

    void close() {
        open = false;
    }

    double getBalance() const { //changed name to better fit / be more professional and descriptive
        return money;
    }
};

int main() {
    Account acc1 ("John Smith", 12345, "savings");

    acc1.deposit(1000);
    acc1.withdraw(250);
    acc1.applyInterest();

    acc1.print();
    acc1.close();

    return 0;
}