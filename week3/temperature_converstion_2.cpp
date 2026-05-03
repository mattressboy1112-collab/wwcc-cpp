#include <iostream>
#include <iomanip>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
using namespace std;

void convertTempurature(float &cel, float &farh, float &kel, int unit) {
    if (unit == 0) {
        farh = ((cel * (9/5)) + 32);
        kel = cel + 273.15;
    } else if (unit == 1) {
        cel = ((farh - 32) * (5/9));
        kel = cel + 273.15;
    } else if (unit == 2) {
        cel = kel - 273.15;
        farh = ((cel * (9/5)) + 32);
    }
}

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif
    float temp_val;
    char temp_unit;
    cout << "Enter a temperature value: "; cin >> temp_val;
    cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): "; cin >> temp_unit;
    float cel, farh, kel;
    cout << endl << "Temperature Conversions:" << endl;
    if (temp_unit == 'F' or temp_unit == 'f') {
        if (temp_val >= -459.67) {
            farh = temp_val;
            convertTempurature(cel,farh,kel,1);
        } else {
            farh = 0;
            cel = 0;
            kel = 0;
        }
    } else if (temp_unit == 'C' or temp_unit == 'c') {
        if (temp_val >= -273.15) {
            cel = temp_val;
            convertTempurature(cel,farh,kel,0);
        } else {
            farh = 0;
            cel = 0;
            kel = 0;
        }
    } else if (temp_unit == 'K' or temp_unit == 'k') {
        if (temp_val >= 0) {
            kel = temp_val;
            convertTempurature(cel,farh,kel,2);
        } else {
            farh = 0;
            cel = 0;
            kel = 0;
        }
    } else {
        cel = 1;
        farh = 1;
        kel = 1;
    }
    if (cel == kel) {
        if (cel == 0) {
            cout << "Error: Invalid Temp - temperature is below absolute zero";
        } else {
            cout << "Error: Invalid Unit - temperature unit given does not fit criteria";
        }
    } else {
        cout << "Celcius: " << fixed << setprecision(2) << cel << "\xC2\xB0F C" << endl;
        cout << "Fahrenheit: " << farh << "\xC2\xB0F F" << endl; //I tried using the solution for the degree symbol, but it did not seem to work. 
        cout << "Kelvin: " << kel << "K" << endl; 
    }
    return 0;
}