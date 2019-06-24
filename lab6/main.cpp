//
//  main.cpp
//  lab6
//
//  Created by Austin Ramberg on 2/15/17.
//  Copyright © 2017 Austin Ramberg. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int starts_with_letter(string filename,char letter){
    
    //Open the filename using an ifstream and check to make sure it worked.
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()){
        cout << "dain't work";
    }

    //Create a new file to save the results in using an ofstream.
    ofstream outfile;
    string res_name="results_";
    res_name+=letter;
    res_name+=".txt";
    outfile.open(res_name);
    
    //Read each word in the file. If it starts with the upper or lower case version of the letter given as input, write the word to your output file followed by a newline and increase your count.
    int count = 0;
    
    string word;
    while (infile >> word)
    {
        if (word[0]==letter || word[0]==letter+32){
            count++;
            outfile << word << "\n";
        }
    }
    
    //Close both files and return the count.
    infile.close();
    outfile.close();
    return count;
    
}


int main() {
    
    cout << "Enter name of file to read: ";
    string fname;
    cin >> fname;
    
    for (char i='A';i<='Z';i++){
        cout << "Count of Words that start with ";
        cout << i;
        cout << " is ";
        cout << starts_with_letter(fname,i);
        cout << endl;
    }
    return 0;
}
