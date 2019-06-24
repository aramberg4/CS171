//---------------------------------
//Program Name: Smaple Program 1
//Purpose: This program converts three English measurements to metric.
//
//Coder: Austin Ramberg
//Date: 1/11/2017
//Last Modified: Austin Ramberg, 1/11/2017
//
//---------------------------------

#include <iostream>
using namespace std;

int main(void)
{
    const double INCHES_PER_METER = 39.37;
    const double POUNDS_PER_KG = 2.24;
    
    int height;
    int weight;
    int temperature;
    
    cout << "METRIC CONVERTER" << endl << endl;
    cout << "Enter your height in inches ";
    cout << "(No fractions, please!) : ";
    cin >> height;
    
    cout << "Enter your weight in pounds ";
    cout << "(No fractions, please!)";
    cin >> weight;
    cout << endl;
    
    cout << "Enter your body temperature in Fahrenheit" << endl;
    cout << "(No fractions, please!)" << endl;
    cin >> temperature;
    
    double metric_height = height/INCHES_PER_METER;
    double metric_weight = weight/POUNDS_PER_KG;
    double metric_temperature=(5*(temperature-32)/9);

    cout << "Your height is " << metric_height << " meters." << endl;
    cout << "Your weight is " << metric_weight << " kilograms." << endl;
    cout << "Your temperature is " << metric_temperature;
    cout << " degrees Centrigrade." << endl;
    
    return 0;
}
