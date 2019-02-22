#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

int magicTrick(int a, int b){
    int m;
    m = 5 * (2*a + 2) - (10 - b);
    return m;
}


int main() {
    int aSecret;
    int bSecret;
    cout << "This trick requires two players.";
    cout << "Person A please pick a number between 1-9: ";
    cin >> aSecret;
    cout << "Person B please pick a number between 1-9: ";
    cin >> bSecret;
    cout << magicTrick(aSecret, bSecret) % 10;
    cout << endl;

    return 0;
}