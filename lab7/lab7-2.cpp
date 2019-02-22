#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main() {

    cout << "Please think of a fraction in your head." << endl;

    //Ask the user for the numerator as an integer
    int numerator;
    cout << "Please enter the numerator: ";
    cin >> numerator;

    //Ask the user for the demoninator as an integer
    int denominator;
    cout << "Please enter the denominator: ";
    cin >> denominator;

    //Computer the GCD
    int g = gcd(numerator, denominator);
    //Divide both by the GCD and print out the new fraction
    cout << "Simplified fraction: ";
    cout << numerator / g;
    cout << "/";
    cout << denominator / g;
    cout << endl;

    return 0;
}