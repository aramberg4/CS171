//
//  prelab5_2.cpp
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

int a = 0;
int b = 0;
int f(int c)
{
    int n = 0;
    a = c;
    if (n < c)
        n = a + b;
    return n;
}

int g(int c) {
    int n = 0;
    int a = c;
    if (n < f(c))
        n = a + b;
    return n;
}

void false_swap1(int& a, int& b)
{
    int c = a;
    a = b;
    b = c; }

int main() {
    int i = 1;
    int b = g(i);
    cout << a + b + i << "\n";
    cout << endl;
    
    int x = 3;
    int y = 4;
    false_swap1(x, y);
    cout << x << " " << y << "\n";
    return 0;
}
