/*
 First CS 171 Example
 Austin Ramberg
 Drexel University
*/
//Preprocessor Directives
#include <iostream>
#include <string>
using namespace std;
//End Preprocessor

//Start of program
int main()
{
/*
    //Write program here
    cout << "Hello World!";
    cout << endl;
    
    cout << "What " << endl << "is " << endl;
    
    //Variables
    int Jeff;
    Jeff = 7;
    float Ted = 12.8;
    char Letter = 't';
    string my_name="Austin Ramberg";
    
    cout << "Jeff is " << Jeff << endl;
    cout << "Ted is " << Ted << endl;
    cout << "Letter is " << Letter << endl;
    cout << "Name is " << my_name << endl;
*/
    cout << "Hello! " << endl;
    cout << "Item Cost: ";
    float cost;
    cin >> cost;
    cout << "Amount: ";
    float cash;
    cin >> cash;
    
    cout << "Change: " << (cash-cost) << endl;
/*
    cout << 7/3
    << " R "
    << 7%3
    <<endl;
    cout << 7.0/3.0 <<endl;
*/
    
    int pennies = (cash-cost)*100;
    int dollars = pennies/100;
    pennies = pennies % 100;
    
    cout << "Twenties: " << dollars /20 <<endl;
    dollars = dollars % 20;
    
    cout << "Tens: " << dollars /10 <<endl;
    dollars = dollars % 10;
    
    cout << "Fives: " << dollars /5 <<endl;
    dollars = dollars % 5;
    
    cout << "Ones: " << dollars /1 <<endl;
    dollars = dollars % 1;
    
    
    
    
    return 0;
}
