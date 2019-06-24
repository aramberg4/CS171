//
//  main.cpp
//  lab4
//
//  Created by Austin Ramberg on 2/1/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int program1(){
    int num = 1;
    int min = 200;
    while( num != 0 && num < 100)
    {
        cout << "Enter a number between 1 and 100. Enter 0 or a number > 100 to quit: ";
        cin >> num;
        if(num < min ){
            min = num;
        }
        
        cout << "The smallest number you have entered in: ";
        cout << min;
        cout << endl;
        
    }
    cout << "Bye";
    cout << endl;
    
    return 0;
}

int program2(){
    cout << "Let's play a guessing game." << endl;
    cout << "Pick a number between 0 and 100." << endl;
    cout << "I will make guesses. Tell me if your number is higher or lower." << endl;
    
    int min = 0;
    int max = 100;
    int guess = 50;
    string horl;
    
    do{
        cout << "Is your secret number " << guess << "?";
        cout << endl;
        cout << "y for yes, l for lower, h for higher";
        cout << endl;
        cin >> horl;
        
        //If the users says h set min=guess+1 and make your next guess (min+max)/2
        if(horl == "h"){
            min = guess + 1;
            guess = (min+max)/2;
        }
        
        //if the user says l set max=guess-1 and make your next guess (min+max)/2
        if(horl == "l"){
            max = guess - 1;
            guess = (min+max)/2;
        }
    }while(horl != "y");
    
    cout << "Your secret number was: " << guess;
    
    cout << endl;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    program1();
    program2();
    
    return 0;
}
