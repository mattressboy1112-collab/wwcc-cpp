#include <iostream>
using namespace std;

int main() {
    int temp;
    char unit;
    cout << "Temperature Converter" << endl << "Enter temperature value: ";
    cin >> temp;
    cout << "Enter unit (C or F): ";
    cin >> unit;
    if (tolower(unit) == 'c') {
        cout << temp << "\370C is equal to " << (temp * 9/5) + 32 << "\370F";
    } else {
        cout << temp << "\370F is equal to " << (temp - 32) * 5/9 << "\370C";
    }
    return 0;
}