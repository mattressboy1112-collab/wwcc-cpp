#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int flips;
    float heads = 0;
    cout << "Coin Flip Simulator" << endl;
    cout << "How many times would you like to simulate? ";
    cin >> flips;
    cout << "Simulating " << flips << " coin flips... \n\n Results: \n";
    for ( int i = 0; i < flips; i++) {
        if (rand() % 2 == 1) {
            heads += 1;
        }
    }
    float tails = (flips - heads);
    cout <<"Heads: " << heads << " (" << (heads/flips)*100.00 << "%)\n";
    cout <<"Tails: " << tails << " (" << (tails/flips)*100.00 << "%)\n";
    return 0;
}