#include <iostream>
using namespace std;
#include <string>

int main() {
    string name;
    string ans;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "! Welcome to C++" << endl;
    cout << "If it takes 10 men to dig a hole," << endl << "how many men does it take to dig half a hole?" << endl;
    cin >> ans;
    cout << "If you answered with any number, (you answered: " << ans << ") then you are incorrect." << endl << "There is no such thing as half a hole, because that would still be a hole!";
    return 0;
}