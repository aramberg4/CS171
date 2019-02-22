#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

//This function will print out a certain number of stars * and spaces
void fractal(int length, int spaces){
    //If length is 1 print out the number of spaces given followed by 1 star
    if(length == 1){
        for(int i=0; i<spaces; i++){
            cout << " ";
        }
        cout << "*";
    //If the length is greater than one do the following:
    }else{
        //Print the fractal pattern with half the length and the same number of spaces.
        fractal(length/2, spaces);
        cout << endl;
        //Print the number of spaces given followed by length stars.
        for(int i=0; i<spaces; i++){
            cout << " ";
        }
        for(int i=0; i<length; i++){
            cout << "* ";
        }
        cout << endl;
        //Print the fractal pattern with half the length and spaces+(length/2) spaces in front of it.
        fractal(length/2, spaces+length);
    } 
}


int main() {
    int length;
    cout << "Enter an integer > 0: ";
    cin >> length;
    fractal(length,0);
    cout << endl;

    return 0;
}