#include <iostream>
using namespace std;

int main(){
	int num;
	cin >> num;
	int yoon = 0;
	
	if(num % 4 == 0 && num % 100 != 0) yoon = 1;
	else if(num % 400 == 0) yoon = 1;
	
	cout << yoon;
}