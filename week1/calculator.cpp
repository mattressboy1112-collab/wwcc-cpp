#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << endl << "Results:" << endl << "Sum:\t\t" << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << "Difference:\t" << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << "Product:\t" << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << "Quotient:\t" << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    return 0;
}