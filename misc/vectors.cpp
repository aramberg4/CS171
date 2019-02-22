#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>//rand
#include <ctime>

using namespace std;
/*
int main()
{
	vector<int> v(10);
 
  	for (int i = 1; i <= 10; i++) v[i] = i * i;
  	for (int i = 1; i <= 10; i++) cout << v[i] << endl;
  	cout << endl;
  	vector<int> v2(10);
  	srand(time(NULL));
  	for(int i=0; i < 10; i++){
  		v2[i]=rand() % 100;
  	}
  	for (int i = 0; i < 10; i++) cout << v2[i] << endl;
}
*/
int main()
{
  	vector<int> v(10);
  	srand(time(NULL));
  	for(int i=0; i < 10; i++){
		int x = rand() % 100;
		for (int j=0; j < i; j++){
			while(x == v[j]){
				x = rand() % 100;
			}
		}
		v[i] = x;
	}
	for (int i = 0; i < 10; i++) cout << v[i] << endl;
}