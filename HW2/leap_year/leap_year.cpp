//
//  leap_year.cpp
//  
//
//  Created by Austin Ramberg on 2/1/17.
//
//  Purpose: This program asks the user to enter a year and returns whether or not
//  that year is a leap year.

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Leap year predicate function
bool leap_year(int year){
    if (year % 4 != 0 ){
        return false;
    }else if (year % 100 != 0){
        return true;
    }else if (year % 400 != 0){
        return false;
    }else{
        return true;
    }
}

int main(){
    
    // Ask user for year and store in variable
    int year;
    cout << "Please enter a year: ";
    cin >> year;
    
    // Check that year is after 1581
    if (year < 1582){
        cout << "Year must be greater than 1581";
        cout << endl;
        return 0;
    }
    
    // Call leap_year function and output appropriate message
    if (leap_year(year)){
        cout << "Your year is a leap year!";
    }else{
        cout << "Your year is not a leap year :(";
    }
    
    cout << endl;
    
    return 0;
}
