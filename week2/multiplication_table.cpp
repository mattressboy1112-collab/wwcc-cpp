#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int start, end, length;
    cout << "Multiplication Table Generator" << endl << endl;
    cout << "Enter starting number: ";
    cin >> start;
    cout << "Enter ending number: ";
    cin >> end;
    if (to_string(end*end).length() > to_string(start*start).length()) {
        length = to_string(end*end).length();
    } else {
        length = to_string(start*start).length();
    }
    string lines(length+2,'-');
    if (start > end) {
        cout << "Error: Starting number must be more than ending number." << endl;
        return 1;
    }
    cout << endl;
    for (int i = start-2; i < end+1; i++)
    {
        for (int i2 = start-1; i2 < end+1; i2++)
        {
            cout << setw(length+1);
            if (i == start-2) {
                if (i2 == start-1)
                {
                    cout << ' ' << " |";
                } else {
                    cout << i2 << " |";
                }
            }else if (i == start-1) {
                cout << lines << '|';
            }else if (i2 == start-1) {
                cout << i << " |";
            }else {
                cout << i*i2 << " |";
            }
        }
        cout << endl;
    }
     
    return 0;
}