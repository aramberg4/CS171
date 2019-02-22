//
//  program2.cpp
//  HW1
//
//  Created by Austin Ramberg on 1/20/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//
//  Purpose: This program asks the  user to input a number
//  of fluid ounces. It then allocates the fluid ounces into 
//  the various units, first starting with barrels, then gallons,
//  and soon, finishing with tablespoons.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	//Conversion rates
	int tableSpoonsPerOunce = 2;
	int ouncesPerGill = 4;
	int gillsPerCup = 2;
	int cupsPerPint = 2;
	int pintsPerQuart = 2;
	int quartsPerGallon = 4;
	int gallonsPerBarrel = 42;

    // Prompt user for ounces
    int totalOunces;
    cout << "How many fluid ounces do you have? ";
    cin >> totalOunces;
    cout << totalOunces << " fluid ounces can be divided into:" << endl;

    // Figure out number of barrels
    int barrels = totalOunces / (gallonsPerBarrel * quartsPerGallon \
    	* pintsPerQuart * cupsPerPint * gillsPerCup * ouncesPerGill);
    cout << barrels << " barrel(s)" << endl;
    int ouncesLeft = totalOunces % (gallonsPerBarrel * quartsPerGallon \
    	* pintsPerQuart * cupsPerPint * gillsPerCup * ouncesPerGill);

    // Figure out number of gallons
    int gallons = ouncesLeft / (quartsPerGallon * pintsPerQuart * \
    	cupsPerPint * gillsPerCup * ouncesPerGill);
    cout << gallons << " gallon(s)" << endl; 
    ouncesLeft = ouncesLeft % (quartsPerGallon * pintsPerQuart * \
    	cupsPerPint * gillsPerCup * ouncesPerGill);  

    // Figure out number of quarts
    int quarts = ouncesLeft / (pintsPerQuart * cupsPerPint * gillsPerCup \
    	* ouncesPerGill);
    cout << quarts << " quart(s)" << endl; 
    ouncesLeft = ouncesLeft % (pintsPerQuart * cupsPerPint * gillsPerCup \
    	* ouncesPerGill);

    // Figure out number of pints
    int pints = ouncesLeft / (cupsPerPint * gillsPerCup * ouncesPerGill);
    cout << pints << " pint(s)" << endl; 
    ouncesLeft = ouncesLeft % (cupsPerPint * gillsPerCup * ouncesPerGill);

    // Figure out number of cups
    int cups = ouncesLeft / (gillsPerCup * ouncesPerGill);
    cout << cups << " cup(s)" << endl; 
    ouncesLeft = ouncesLeft % (gillsPerCup * ouncesPerGill);

    // Figure out number of gills
    int gills = ouncesLeft / (ouncesPerGill);
    cout << gills << " gill(s)" << endl; 
    ouncesLeft = ouncesLeft % (ouncesPerGill);

    // Figure out number of tablespoons
    int tableSpoons = ouncesLeft * (tableSpoonsPerOunce);
    cout << tableSpoons << " tablespoon(s)" << endl; 

    cout << endl;

    return 0;
}