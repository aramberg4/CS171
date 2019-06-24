//
//  main.cpp
//  lab2
//
//  Created by Austin Ramberg on 1/18/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    
    // Part 1
    int n;
    cout << "Please enter an integer:";
    cin >> n;
    int n2;
    cout << "Please enter another integer:";
    cin >> n2;
    cout << "Sum: ";
    cout << n + n2 << endl;
    cout << "Difference: ";
    cout << n - n2 << endl;
    cout << "Product: ";
    cout << n * n2 << endl;
    cout << "Average: ";
    cout << float (n + n2) /2 << endl;
    cout << "Distance: ";
    cout << abs(n - n2) << endl;
    cout << "Max: ";
    cout << max(n,n2) << endl;
    cout << "Min: ";
    cout << min(n,n2) << endl;
    
    //Part 2
    float r;
    float Pi = atan(1)*4;
    cout << "Enter Radius (as decimal number): ";
    cin >> r;
    cout << "The Cirumference of a circle with this radius is: ";
    cout << 2 * Pi * r << endl;
    cout << "The Area of a circle with this radius is: ";
    cout << Pi * r * r<< endl;
    cout << "The Surface Area of a sphere with this radius is: ";
    cout << 4 * Pi * r * r<< endl;
    cout << "The Volume of a sphere with this radius is: ";
    cout << (4.0/3.0) * Pi * r * r * r << endl;
    
    //Part 3
    float l;
    float w;
    cout << "Enter a length: ";
    cin >> l;
    cout << "Enter a width: ";
    cin >> w;
    cout << "The area of the rectangle is: ";
    cout << l*w << endl;
    cout << "The perimeter of the rectangle is: ";
    cout << 2*l + 2*w << endl;
    cout << "The diagonal of the rectangle is: ";
    cout << sqrt(l*l + w*w) << endl;
    return 0;
}
