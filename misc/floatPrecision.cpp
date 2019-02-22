#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
//End Preprocessor

//Start of program
int main()
{
    float a = 9.0;
    int b = 5;
    cout << "Division: " << a / b;
    cout << endl;
    //Floating Point Error in addition/subtraction
    float d1 = 1000000.00;
    float d2 = 0.05;
    cout << d1 << " + " << d2 << " - " << d1 << " = " << (d1+d2-d1) 
    << endl;
    
    //Using Multiplication to introduce error
    float d3 = 0.1;
    cout << "0.1*10^8+10^7-2*10^7=0" << endl;
    //cout << d3 << endl;
    cout << (d3*100000000.0)+10000000.0-20000000 << endl;
    
    cout << "Numbers are harder to prove equal" << endl;
    cout << "(1.0 / 5.0) + (2.0 / 5.0) + (4.0 / 5.0) = "
        << setprecision(30)
            << (1.0 / 5.0) + (2.0 / 5.0) + (4.0 / 5.0) << endl ;
    float x=(1.0 / 5.0) + (2.0 / 5.0) + (4.0 / 5.0);
    if(x==1.4)
    {
        cout << " X is exactly 1.4" << endl;
    }else
    {
        cout << " X is off by " << setprecision(30) << (1.4-x) << endl;
    }

    return 0;

    
}
