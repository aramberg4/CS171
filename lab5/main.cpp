//
//  main.cpp
//  lab5
//
//  Created by Austin Ramberg on 2/8/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double celsius(double f){
    double c = (f - 32) / 1.8;
    return c;
}

string roman(int num, string one, string five, string ten){
    string roman;
    
    switch(num){
        case 1: roman = one;
            break;
        case 2: roman = one + one;
            break;
        case 3: roman = one + one + one;
            break;
        case 4: roman = one + five;
            break;
        case 5: roman = five;
            break;
        case 6: roman = five + one;
            break;
        case 7: roman = five + one + one;
            break;
        case 8: roman = five + one + one + one;
            break;
        case 9: roman = one + ten;
            break;
        default: roman = "";
            break;

    }
    return roman;
}

string roman_num(int num){
    int rem;
    string romanOut = "";
    
    rem = num % 10;
    romanOut = roman(rem, "I", "V", "X") + romanOut;
    num /= 10;
    
    rem = num % 10;
    romanOut = roman(rem, "X", "L", "C") + romanOut;
    num /= 10;
    
    rem = num % 10;
    romanOut = roman(rem, "C", "D", "M") + romanOut;
    num /= 10;
    
    rem = num % 10;
    romanOut = roman(rem, "M", "v", "x") + romanOut;
    num /= 10;
    
    return romanOut;

}


int main() {
    // insert code here...

   cout << "Fahrenheit to Celsius Converter. Enter number greater than 1,000 to quit.";
    cout << endl;
    double f;
    do{
        cout << "Enter Temp in Fahrenheit: ";
        cin >> f;        cout << "In Celsius this is: ";

        double c = celsius(f);
        cout << c;
        cout << endl;
    }while(f <= 1000);


    cout << "Roman Number Generator. Enter 0 to quit.";
    cout << endl;
    
    int num;
    
    do{
        cout << "Enter a number between 1 and 3,999: ";
        cin >> num;
        cout << roman_num(num);
        cout << endl;
    }while( num>0);

    
    return 0;
}
