#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
//End Preprocessor

//Start of program
int main()
{
	int s = 1;
	int n = 1;

	do
	{
		s = s + n;
		n++;
	}
	while (s < 10 * n);
    
    cout << s << endl;
    cout << n << endl;
}