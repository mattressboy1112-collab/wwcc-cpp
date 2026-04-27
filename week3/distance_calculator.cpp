#include <iostream>
#include <cmath> //allows the use of pow, to easily square and square root.
using namespace std;

float calculateDistance(float x1, float y1,float x2,float y2) {
    return pow((pow((x2-x1),2) + pow((y2-y1),2)),0.5); //entire equation from assignment page, formatted for cpp.
}

tuple<float, float> calculateMidpoint(float x1, float y1,float x2,float y2) {
    float xAverage = (x1 + x2)/2; // adds both numbers together and gets the average
    float yAverage = (y1 + y2)/2;
    return {xAverage,yAverage}; // returns both numbers
}

int main() {
    float x1,x2,y1,y2;
    cout << "Enter the coordinates of the first point:" << endl;
    cout << "x1: "; cin >> x1;
    cout << "y1: "; cin >> y1;
    cout << "Enter the coordinates of the second point:" << endl;
    cout << "x2: "; cin >> x2;
    cout << "y2: "; cin >> y2;
    cout << "The distance between (" << x1 << ',' << y1 << ") and (" << x2 << ',' << y2 << ") is: " << calculateDistance(x1,y1,x2,y2) << endl; //runs and prints the calculations
    auto [out1, out2] = calculateMidpoint(x1,y1,x2,y2); // gets the midpoint position from the function
    cout << "The midpoint is (" << out1 << ',' << out2 << ')';
    return 0;
}