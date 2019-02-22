//
//  bac.cpp
//  
//
//  Created by Austin Ramberg on 2/16/17.
//
// This program	tasks the user to enter	the	weight,	sex	and	time since their last drink, and then prints
// out a table of information showing the status according to the BAC


#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Function that accepts all necessary input variables to calculate BAC as params and returns M and F BAC
void computeBloodAlcoholConcentration(int numDrinks, int weight,
                                      int duration, double &maleBAC, double &femaleBAC){
	//Declare constants
    const float maleConstant = 3.8;
    const float femaleConstant = 4.5;
    const float reductionTime = 40;
    const float reductionRate = 0.01;
    
    //Perform BAC calculations for M and F using float division
    maleBAC = (float)numDrinks / (float)weight * maleConstant - reductionRate * 
    	(float)duration / (float)reductionTime;
    
    femaleBAC = (float)numDrinks / (float)weight * femaleConstant - reductionRate * 
    	(float)duration / (float)reductionTime;
}

//Function that takes bac as param and returns the appropriate status message
string impairment(double bac){
    const double safe = 0.00;
    const double someImpairment = 0.04;
    const double significantAffected = 0.08;
    const double someCriminalPenalties = 0.10;
    const double deathPossible = 0.30;
    const string SAFE = "Safe To Drive";
    const string SOMEIMPAIR = "Some Impairment";
    const string SIGNIFICANT = "Driving Skills Significantly Affected";
    const string MOST_STATES = "Criminal Penalties in Most US States";
    const string ALL_STATES = "Legally Intoxicated - Criminal Penalties in All US States";
    const string YOURE_DEAD = "Death is Possible!";
    
    if(bac == safe){
        return SAFE;
    }else if (bac <= someImpairment){
        return SOMEIMPAIR;
    }else if (bac <= significantAffected){
        return SIGNIFICANT;
    }else if (bac <= someCriminalPenalties){
        return MOST_STATES;
    }else if (bac < deathPossible){
        return ALL_STATES;
    }else if (bac >= deathPossible){
        return YOURE_DEAD;
    }else{
        return "Error";
    }
}

//Function that takes message, upperbound, and lowerbound as params and continues to prompt user for an input
//while input is not within range and then returns input 
int promptForInteger(const string &message, int lower, int upper){
    int input;
    do{
        cout << message;
        cin >> input;
    }while(input > upper || input < lower);
    return input;
}
//Function prompts uaser for sex and returns input (M or F)
char promptForMorF(const string &message){
    char input;
    do{
        cout << message;
        cin >> input;
    }while(input != 'M' && input != 'F');
    return input;
}

//Function that computes BAC for 10 drinks and formats a table with corresponding status
void showImpairmentChart(int weight, int duration, bool isMale){
    int drinks = 0;
    double maleBAC = 0.0;
    double femaleBAC = 0.0;

    //Table formatting
    cout << weight << " pounds"<< ",";
    if(isMale){
    	cout << "male" << ",";
    }else{
    	cout << "female" << ",";
    }
    cout << duration << " minutes since last drink";
    cout << endl;

    cout << "# drinks";
    cout << "   ";
    cout << "BAC";
    cout << "   ";
    cout << "Status";
    cout << endl;

    while(drinks < 11){
        cout << drinks;
        cout << "   ";
        //Compute BAC
        computeBloodAlcoholConcentration(drinks, weight, duration, maleBAC, femaleBAC);

        if(isMale){
            cout << maleBAC;
            cout << "   ";
            cout << impairment(maleBAC);
        }else{
            cout << femaleBAC;
            cout << "   ";
            cout << impairment(femaleBAC);
        }
        cout << endl;
        drinks++;
    }
}

int main(){
	//Prompt user for inputs using promptForInteger function
    int weight = promptForInteger("Please enter your weight in pounds: ", 0, 400);
    
    int duration = promptForInteger("Please enter the amount of minutes since your last drink: ", 0, 400);
    
    char sex = promptForMorF("Please enter your sex ('M' or 'F'): ");
    
    bool isMale;

    //Set isMale according to whether sex is M or F
    if(sex == 'M'){
        isMale = true;
    }else{
        isMale = false;
    }

    //Call showImpairmentChart fucntion passing user inputs as params
    showImpairmentChart(weight, duration, isMale);
    
    cout << endl;
    return 0;
}