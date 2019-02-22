#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main() {
 	cout << "Enter name of file to read: ";
    string fname;
    cin >> fname;

	//Open the filename using an ifstream and check to make sure it worked.
    ifstream infile;
    infile.open(fname);
    //infile << "Hello World!";
    //if (!infile.is_open()){
    //    cout << "dain't work";
    //}

    //Create a new file to save the results in using an ofstream.
    ofstream outfile;
    string res_name="results_";
    res_name+=".txt";
    outfile.open(res_name);
    outfile << "Hello World!!!!!";

    //Close both files and return the count.
    infile.close();
    outfile.close();

    return 0;
}