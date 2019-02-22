//
//  prelab5.cpp
//  
//
//  Created by Austin Ramberg on 2/7/17.
//
//

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

double f(double x);
double g(double x);
double h(double x);
double k(double x);

double f(double x) { return g(x) + sqrt(h(x)); }
double g(double x) { return 4 * h(x); }
double h(double x) { return x * x + k(x) - 1; }
double k(double x) { return 2 * (x + 1); }

int main(){
    cout << "a. " << f(2) << endl;
    cout << "b. " << g(h(2)) << endl;
    cout << "c. " << k(g(2) + h(2))<< endl;
    cout << "d. " << f(0) + f(1) + f(2)<< endl;
    cout << "e. " << f(-1) + g(-1) + h(-1) + k(-1)<< endl;
    cout << 2 * g(1) << endl;
    cout << g(2) + h(2) << endl;
    cout << f(0) << endl;
    cout << f(1) << endl;
    
    
    
    return 0;
}
