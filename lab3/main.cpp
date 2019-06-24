//
//  main.cpp
//  lab3
//
//  Created by Austin Ramberg on 1/25/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
//End Preprocessor

int main(int argc, const char * argv[]) {
    // Part 1
    int month;
    cout << "Enter a month: ";
    cin >> month;
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        cout << "31 days" << endl;
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        cout << "30 days" << endl;
    }else{
        cout << "28 or 29 days" << endl;
    }
    
    // Part 2

    string s1;
    string s2;
    string s3;
    
    
    cout << "Enter three strings: ";
    cin >> s1;
    cin >> s2;
    cin >> s3;

    
 
    if ( s1 < s2 && s1 < s3 ){
        cout << s1 << endl;
        if (s2 < s3){
            cout << s2 << endl;
            cout << s3 << endl;
        }else{
            cout << s3 << endl;
            cout << s2 << endl;
        }
    }else if ( s2 < s1 && s2 > s3 ){
        cout << s2 << endl;
        if (s1 < s3){
            cout << s1 << endl;
            cout << s3 << endl;
        }else{
            cout << s3 << endl;
            cout << s1 << endl;
        }
    }else if ( s3 < s1 && s3 < s2 ){
        cout << s3 << endl;
        if (s1 < s2){
            cout << s1 << endl;
            cout << s2 << endl;
        }else{
            cout << s2 << endl;
            cout << s1 << endl;
        }
    }
    
    // Part 3

    float hours_worked;
    float wage;
    int normal_hours = 40;
    
    cout << "How may hours did you work this week? ";
    cin >> hours_worked;
    cout << "How much are you paid per hour? ";
    cin >> wage;
    
    float pay;
    pay = (hours_worked * wage);
    if (hours_worked > normal_hours){
      pay +=  (hours_worked - normal_hours) * wage * 1.5;
    }
    cout << pay;
    
    cout << endl;
    return 0;
}
