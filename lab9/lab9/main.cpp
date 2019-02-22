//
//  main.cpp
//  lab9
//
//  Created by Austin Ramberg on 3/8/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>//rand
#include <ctime>
#include <string>
#include <vector>
using namespace std;

int main() {
    double a;
    double v;
    double totalFuel;
    double g = -1.63;
    int s = 0;
    double f;
    cout << "Enter an initial altitude: ";
    cin >> a;
    cout << "Enter an initial velocity: ";
    cin >> v;
    cout << "Enter the initial fuel amount: ";
    cin >> totalFuel;
    
    do{
        if(totalFuel > 0){
            do{
                cout << "How much fuel do you want to burn? ";
                cin >> f;
            }while( f < 0 || f > totalFuel);
            totalFuel = totalFuel - f;
        }else{
            f = 0;
        }
        v = v + (g + 0.1 * f);
        a = a + v;
        s++;
        cout << "After " << s;
        if(a > 0){
            cout << " seconds Altitude is " << a;
        }else{
            cout << " seconds Altitude is 0.00";
        }
        cout << ", velocity is " << v;
        cout << endl;
    }while(a > 0);
    
    if(v >= -2){
        cout << "We landed safely!!";
        cout << endl;
    }else{
        cout << "We crashed!";
        cout << endl;
    }

    
    return 0;
}
