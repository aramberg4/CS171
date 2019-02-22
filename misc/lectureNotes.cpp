#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
//End Preprocessor

//Start of program
int main()
{
/*
    float num1 = 10;
    int num2 = 10;

    if (num1 == 10){
        cout << "True";
        cout << endl;
    }else{
        cout << "False";
        cout << endl;
    }
    if (num2 == 10){
        cout << "True";
        cout << endl;
    }else{
        cout << "False";
        cout << endl;
    }

    if (num1 == 10 && num2 == 10){
        cout << "True";
        cout << endl;
    }else{
        cout << "False";
        cout << endl;
    }

    if ((num1 && num2) == (num2 && num1)){
        cout << "True";
        cout << endl;
    }else{
        cout << "False";
        cout << endl;
    }
    int x = 1;
    int y = 1;
    int s = 0;
    if (x > 0) s++;
    if (y > 0) s++;
    cout << s << endl;
    s = 0;
    if (x > 0) s++;
    else if (y > 0) s++;
    cout << s << endl;
*/
    int x = 6;
    int y = 1;

    //Nested if:
    if (x >= 0)
    {
        if (y >= 0)
        {
            cout <<  "Success";
        }
    }
    //If/else/else:
    if (x >= 5)
    {
        cout <<  "Success";
    } else if ( y >= 5)
    {
        cout <<  "Success";
    }else
    {
        cout <<  "Failure";
    }
    endl;
    return 0;

    
}