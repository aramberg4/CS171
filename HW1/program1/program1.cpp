//
//  program1.cpp
//  HW1
//
//  Created by Austin Ramberg on 1/20/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//
//  Purpose: This program projects the cost of a college education for high 
//  school students who are looking for a college given the student's initial 
//  tuition and percentage of yearly tution increase.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
    
    // Prompt user for tuition
    long t;
    cout << "Please enter the initial tuition amount: ";
    cin >> t;

    // Convert tuition to pennies
    int penniesPerDollar = 100;
    t = t*penniesPerDollar;

    // Prompt user for yearly tuition increase
    double r;
    cout << "Enter the yearly tuition increase (as a percentage): ";
    cin >> r;

    // Divide the percentage by 100 and add 1 to get R
    // the rate used to multiply the tuition
    float R = 1 + (r/100);

    // Initialize total tuition to 0
    long totalTuition = 0;

    // Format output
    cout.setf(ios::fixed); // decimals are fixed
    cout.setf(ios::showpoint); // show decimals
    cout.precision(2); // two decimal places

    // Print first year's tuition
    cout << "Tuition of year 1 is: $" << float(t/penniesPerDollar);
    cout << endl;
    // Add to total tuition
    totalTuition += t;

    // Multiply tuition by rate to get next year's tuition
    t = t*R;
    // Convert back to dollars
    float dollars = t/penniesPerDollar;
    float cents = float (t % penniesPerDollar) / float(penniesPerDollar);
    float T = dollars + cents;
    // Print tuition
    cout << "Tuition of year 2 is: $" << T;
    cout << endl;
    // Add to total tuition
    totalTuition += t;

    // Multiply tuition by rate to get next year's tuition
    t = t*R;
    // Convert back to dollars
    dollars = t/penniesPerDollar;
    cents = float (t % penniesPerDollar) / float(penniesPerDollar);
    T = dollars + cents;
    // Print tuition
    cout << "Tuition of year 3 is: $" << T;
    cout << endl;
    // Add to total tuition
    totalTuition += t;

    // Multiply tuition by rate to get next year's tuition
    t = t*R;
    // Convert back to dollars
    dollars = t/penniesPerDollar;
    cents = float (t % penniesPerDollar) / float(penniesPerDollar);
    T = dollars + cents;
    // Print tuition
    cout << "Tuition of year 4 is: $" << T;
    cout << endl;
    // Add to total tuition
    totalTuition += t;

    // Multiply tuition by rate to get next year's tuition
    t = t*R;
    // Convert back to dollars
    dollars = t/penniesPerDollar;
    cents = float (t % penniesPerDollar) / float(penniesPerDollar);
    T = dollars + cents;
    // Print tuition
    cout << "Tuition of year 5 is: $" << T;
    cout << endl;
    // Add to total tuition
    totalTuition += t;

    // Print total tuition
    dollars = totalTuition/penniesPerDollar;
    cents = float (totalTuition % penniesPerDollar) / float(penniesPerDollar);
    T = dollars + cents;
    cout << "Total Tuition Cost is $" << T;
    cout << endl;

    return 0;
}

