#include <iostream>
using namespace std;


int h(int &x)
{
	x=x+2;
	cout << "x="<< x
		<< endl;
	return 2*x;
}

int main()
{
	int a=7;
	int b=h(a);
	cout << "a=" << a
		<< endl;
	cout << "b=" << b
		<< endl;
	return 0;
}