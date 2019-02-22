//
//  hw5.cpp
//
//
//  Created by Austin Ramberg on 3/16/17.
//
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
#define G 5 //acceleration due to gravity

// Output current status of spacecraft to selected output stream
void reportStatus(ostream &os, double time, double height,
                  double velocity, double fuel, string name){
    
    os << "Status of your " << name << " spacecraft: " << endl;
    os << "Time : " << time << " seconds" << endl;
    os << "Height: " << height << " feet" << endl;
    os << "Speed : " << velocity << " feet/second" << endl;
    os << "Fuel : " << fuel << endl;
    os << endl;
}

// Contains all the calculations to change spacecraft variables while in flight
void updateStatus(double &velocity, double burnAmount, double
                  &fuelRemaining, double &height){
    fuelRemaining = fuelRemaining - burnAmount;
    if(fuelRemaining <= 0){
        fuelRemaining = 0;
    }
    double oldVelocity = velocity;
    velocity = velocity + G - burnAmount;
    height = height - (oldVelocity + velocity)/2;
}
// Reads in instructions from input stream and outputs to selcted output stream
void introduction(istream &is, ostream &os, string target,
                  string replacement){
    string str;
    string word;
    while(is) {
        getline(is, str);
        size_t pos = 0;
        // Look for target string, replace in place if found
        while((pos = str.find(target, pos)) != std::string::npos){
            str.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
        if(is){ os << str << endl;}
    }
}
// Performs recalculation for exact time of landing and exact velocity at time of landing
void touchdown(double &elapsedTime, double &velocity, double
               &burnAmount, double &height){
    // "Undo" current values to get previous values
    double oldTime = elapsedTime - 1;
    double oldVelocity = velocity - G + burnAmount;
    double oldHeight = height + (oldVelocity + velocity)/2;
    double altJ = (sqrt(oldVelocity*oldVelocity + oldHeight*(10 - 2*burnAmount)) - oldVelocity) / (G -burnAmount);
    // Calculate values
    elapsedTime = elapsedTime - 1 + altJ;
    velocity = oldVelocity + (G - burnAmount) * altJ;
    height = 0;
}
// Outputs appropriate message to selected output stream based on impact velocity
void finalAnalysis(ostream &os, double velocity){
    if(velocity == 0){
        os << "Congratulations! A perfect landing!!" << endl;
        os << "Your license will be renewed...later.";
    }else if(velocity < 2){
        os << "A little bumpy";
    }else if(velocity >= 2 && velocity < 5){
        os << "You blew it!!!!!";
        os << "Your family will be notified...by post.";
    }else if(velocity >= 5 && velocity < 10){
        os << "Your ship is a heap of junk!!!!";
        os << "Your family will be notified...by post.";
    }else if(velocity >= 10 && velocity < 30){
        os << "You blasted a huge crater!!!!!";
        os << "Your family will be notified...by post.";
    }else if(velocity >= 30 && velocity < 50){
        os << "Your ship is a wreck!!!!";
        os << "Your family will be notified...by post.";
    }else if(velocity >= 50){
        os << "You totaled an entire mountain!!!!!";
        os << "Your family will be notified...by post.";
    }
}
// Main
int main() {
    // Initial altitude (height)
    double a = 1000;
    // Initial velocity
    double v = 50;
    // Starting fuel
    double totalFuel = 150;
    // Elapsed time
    double s = 0;//seconds
    // Amount of fuel to burn each second
    double f;//burnAmount
    // Yes or no
    string yorn;
    // Outfile
    ofstream outfile;
    // Name of spaceship
    string name;
    // Last (old) burnamount
    double flast;
    // Name of output file
    string outfileName;
    
    // User prompts
    cout << "Please enter the name of your spacecraft: ";
    cin >> name;
    
    cout << "Do you wish to save a log of this program in a separate file? (y/n)? ";
    cin >> yorn;
    if(yorn == "y" || yorn == "Y"){
        cout << "Please enter the name of your output file: ";
        cin >> outfileName;
        outfile.open(outfileName);
    }
    cout << "Do you want instructions (y/n)? ";
    cin >> yorn;
    if(yorn == "y" || yorn == "Y"){
        
        ifstream infile;
        //Open the filename using an ifstream and check to make sure it worked.
        infile.open("input.txt");
        if (!infile.is_open()){
            cout << "error opening infile";
        }
        introduction(infile, cout, "$SPACECRAFT", name);
        if(outfile.is_open()){introduction(infile, outfile, "$SPACECRAFT", name);}
        cout << endl;
        if(outfile.is_open()){outfile << endl;}
        infile.close();
    }
    // Flight loop
    do{
        // Report spacecraft status
        reportStatus(cout, s, a, v, totalFuel, name);
        if(outfile.is_open()){
           reportStatus(outfile, s, a, v, totalFuel, name);
        }
        
        // If there is fuel left, ask user how much they would like to burn
        if(totalFuel > 0){
            do{
                cout << "How much fuel do you want to burn? (0-30) ";
                outfile << "How much fuel do you want to burn? (0-30) ";
                cin >> f;
                outfile << f;
            }while( f < 0 || f > 30);// between 0 and 30 units
            
        }else{
            // If there is no fuel left, output message
            f = 0;
            flast = f;//Keep track of last fuel amount if spaceship lands
            cout << "**** OUT OF FUEL ****" << endl;
            if(outfile.is_open()){outfile << "**** OUT OF FUEL ****" << endl;}
        }
        // Update values
        updateStatus(v, f, totalFuel, a);
        // Add one (second) to elasped time
        s++;
        
        cout << endl;
        outfile << endl;
    }while(a > 0);
    // Recalculate impact values
    cout << "**** CONTACT ****" << endl;
    if(outfile.is_open()){outfile << "**** CONTACT ****" << endl;}
    touchdown(s, v, f, a);
    reportStatus(cout, s, a, v, totalFuel, name);
    if(outfile.is_open()){reportStatus(outfile, s, a, v, totalFuel, name);}
    // Output final analysis message
    finalAnalysis(cout, v);
    if(outfile.is_open()){finalAnalysis(outfile, v);}
    cout << endl;
    outfile.close();
    
    return 0;
}
