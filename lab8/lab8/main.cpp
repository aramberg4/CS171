//
//  main.cpp
//  lab8
//
//  Created by Austin Ramberg on 3/1/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.


#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//  Searchs the file given and fill in a vector with the number
//  of people who drink at each level 1-5, for both males and females
//  Only count people with min_age <= age <= max_age
//  results = [M1, F1, M2, F2, M3, F3, M4, F4, M5, F5]
void analyze(string filename, vector<int> & results, int min_age, int max_age){
    
    //  Open the filename using an ifstream and check to make sure it worked.
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()){
        cout << "wot n tarnation";
    }
    string a;
    int b, c;
    
    while (infile >> a >> b >> c)
    {
        if( b >= min_age && b <= max_age){
            if( a == "M"){
                results[c*2-2] += 1;
            }else{
                results[c*2-1] += 1;
            }
        }
    }
    
    infile.close();

}

//  Print a single row X for a 10, int 1-9 for remainder
//  Example: Prints 27 as XX7 and 31 as XXX1
void print_bar(int num){
    int x, y;
    x = num / 10;
    y = num % 10;
    cout << num;
    cout << " ";
    for(int i = 0; i < x; i++){
        cout << "X";
    }
    cout << y;
    cout << endl;
}

//  Prints out the vector as a bar chart
void print_chart(vector<int> & results){
    for(int i = 0; i < 10; i++){
        if(i%2 ==0){
            cout << "M Freq. ";
            cout << (i+2)/2 << " ";
        }else{
            cout << "F Freq. ";
            cout << (i+1)/2 << " ";
        }
        print_bar(results[i]);
    }
}

int main() {
    int min;
    int max;
    string fname;
    vector<int> results(10);
    
    cout << "Analyze Alcohol Data" << endl;
    cout << "Enter name of file to read: ";
    cin >> fname;
    cout << "Enter Minimum Age as integer: ";
    cin >> min;
    cout << "Enter Max Age as integer: ";
    cin >> max;
    
    analyze(fname, results, min, max);
    //for (int i = 0; i < 10; i++) cout << results[i] << endl;
    print_chart(results);
    
    cout << endl;
    return 0;
}
