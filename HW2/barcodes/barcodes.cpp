//
//  barcodes.cpp
//  
//
//  Created by Austin Ramberg on 2/2/17.
//
//  Purpose: This program asks the user to enter a valid zipcode and then converts
//  it to a barcode.


#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Program 2
int makeCheckDigit(int zipcode){
    const int NUMBER_OF_DIGITS_IN_A_ZIP_CODE = 5;
    
    // Remainder - last digit of zipcode
    int rem;
    int sum = 0;
    
    // Iterate through every digit of zipcode and sum
    for (int i = 0; i < NUMBER_OF_DIGITS_IN_A_ZIP_CODE; i++){
        rem = zipcode % 10;
        sum += rem;
        zipcode /= 10;
    }
    
    // Calculate check digit
    int checkDigit = 10 - (sum % 10);
    return checkDigit;
}

// Program 3
string convertDigit(int value){

    // Encoding constants
    const string ONEBAR = ":::||";
    const string TWOBAR = "::|:|";
    const string THREEBAR = "::||:";
    const string FOURBAR = ":|::|";
    const string FIVEBAR = ":|:|:";
    const string SIXBAR = ":||::";
    const string SEVENBAR = "|:::|";
    const string EIGHTBAR = "|::|:";
    const string NINEBAR = "|:|::";
    const string ZEROBAR = "||:::";
    const int NUMBER_OF_DIGITS_IN_A_ZIP_CODE = 5;
    
    // Assign encoding to appropriate digit
    if (value == 0){
        return ZEROBAR;
    }else if (value == 1){
        return ONEBAR;
    }else if (value == 2){
        return TWOBAR;
    }else if (value == 3){
        return THREEBAR;
    }else if (value == 4){
        return FOURBAR;
    }else if (value == 5){
        return FIVEBAR;
    }else if (value == 6){
        return SIXBAR;
    }else if (value == 7){
        return SEVENBAR;
    }else if (value == 8){
        return EIGHTBAR;
    }else if (value == 9){
        return NINEBAR;
    }else{
        cout << "Input not valid";
    return 0;
    }
}

// Program 4
string barcode(int zipcode){
    const int NUMBER_OF_DIGITS_IN_A_ZIP_CODE = 5;
    
    int checkDigit = makeCheckDigit(zipcode);
    
    int rem;
    string barcode;
    
    // Iterate through zipcode
    for (int i = 0; i < NUMBER_OF_DIGITS_IN_A_ZIP_CODE; i++){
        rem = zipcode % 10;
        // Convert digit to encoding and add to barcode
        barcode = convertDigit(rem) + barcode;
        zipcode /= 10;
    }
    
    // Add check digit encoding to the end of the barcode
    barcode = barcode + convertDigit(checkDigit);
    return barcode;
    
}
// Program 5
int main(){
    
    // Ask user for a valid zipcode
    int zipcode;
    cout << "Enter zipcode: ";
    cin >> zipcode;
    
    // Make sure it is nonnegative
    if(zipcode > 0){
        // Convert to barcode
        cout << barcode(zipcode);
    }else{
        cout << "Please enter a valid zipcode.";
    }
    
    cout << endl;
    
    return 0;
}

