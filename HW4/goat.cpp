//
//  goat.cpp
//  
//
//  Created by Austin Ramberg on 3/3/17.
//
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>//rand
#include <ctime>
#include <string>
#include <cstdio>
using namespace std;

// Function sets all three doors to 'G' and then randomly picks one to be 'C'
void setupDoors(char &door1, char &door2, char &door3){
    door1 = 'G';
    door2 = 'G';
    door3 = 'G';
    int num = rand() % 3 + 1;

    switch (num) {
        case 1:
            door1 = 'C';
            break;
        case 2:
            door2 = 'C';
            break;
        case 3:
            door3 = 'C';
            break;
        default:
            break;
    }
}

// Determines which door has the car given Monty's door and the player's door
// and return the number of that door
int doorWithCarFunc(char door1, char door2, char door3){
    int doorWithCar;
    if(door1 == 'C'){
        doorWithCar = 1;
    }else if(door2 == 'C'){
        doorWithCar = 2;
    }else if(door3 =='C'){
        doorWithCar = 3;
    }
    return doorWithCar;
}

// Function randomly sets a	value 1	through	3 for doorPlayer. Then sets a value for
// doorMonty to	an integer 1–3 that obeys the constraint that Monty never picks
// the same door as	the	player and never picks the door	that has the car.
void pickDoorChoices(char door1, char door2, char door3, int
                     &doorPlayer, int &doorMonty){
    int doorWithCar = doorWithCarFunc(door1, door2, door3);
    doorPlayer = rand() % 3 + 1;
    
    do {
        doorMonty = rand() % 3 + 1;
    }while(doorMonty==doorPlayer || doorMonty==doorWithCar);

}

// Determines if the player picked the right door given their choice and the setup of
// the doors (true = win, false = loss)
bool isWinner(char door1, char door2, char door3, int
              &doorPlayer){
    int doorWithCar = doorWithCarFunc(door1, door2, door3);
    if(doorWithCar == doorPlayer){
        return true;
    }else{
        return false;
    }
}
// Switches player's door choice with the door that Monty did not open
void switchDoors(int &doorPlayer, int &doorMonty){
    int numberOfDoors = 3;
    int otherChoice;
    for(int i = 1; i <= numberOfDoors; i++){
        if(i != doorPlayer && i != doorMonty){
            otherChoice = i;
        }
    }
    doorPlayer = otherChoice;
}

// Simulates the game in which the player does not switch doors and returns boolean
// true for win, false for loss
bool strategy1(char door1, char door2, char door3, int
               &doorPlayer, int &doorMonty){
    setupDoors(door1, door2, door3);
    pickDoorChoices(door1, door2, door3, doorPlayer, doorMonty);
    return isWinner(door1, door2, door3, doorPlayer);
}

// Simulates the game in which the player does switch doors and returns boolean
// true for win, false for loss
bool strategy2(char door1, char door2, char door3, int
&doorPlayer, int &doorMonty){
    setupDoors(door1, door2, door3);
    pickDoorChoices(door1, door2, door3, doorPlayer, doorMonty);
    switchDoors(doorPlayer, doorMonty);
    return isWinner(door1, door2, door3, doorPlayer);
}

// Runs tests of the simulations given a strategy and number of iterations and returns
// the number of tests in which the player won
int runTests(int strategy, int iterations, char door1,
             char door2, char door3, int
             &doorPlayer, int &doorMonty ){
    int i = 0;
    int winCounter = 0;
    if(strategy == 1){
        while(i < iterations){
            
            if(strategy1(door1, door2, door3, doorPlayer, doorMonty)){
                winCounter++;
            }
                i++;
        }
    }else{
        while(i < iterations){
            
            if(strategy2(door1, door2, door3, doorPlayer, doorMonty)){
                winCounter++;
            }
            i++;
        }
    }
    return winCounter;
}

int main() {
    // Set rand() seed
    srand(time(0));
    //Declare variables
    char door1;
    char door2;
    char door3;
    int doorPlayer;
    int doorMonty;
    
    // Run 10,000 tests for strategy 1
    int results1 = runTests(1, 10000, door1, door2, door3, doorPlayer, doorMonty);
    // Display results as a percentage
    cout << "Strategy 1 won: " << results1/100 << "." << results1 % 100 << "% of the time."<< endl;
    
    // Run 10,000 tests for strategy 2
    int results2 = runTests(2, 10000, door1, door2, door3, doorPlayer, doorMonty);
    // Display results as a percentage
    cout << "Strategy 2 won: " << results2/100 << "." << results2 % 100 << "% of the time."<< endl;
    cout << endl;
    return 0;
}
