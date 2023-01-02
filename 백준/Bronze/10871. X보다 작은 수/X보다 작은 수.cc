#include <iostream>
#include <string>
using namespace std;

int main(){
	int size, under;
	
	cin >> size >> under;
	
	int num;
	for(int i = 0; i < size; i++){
		cin >> num;
		if(num < under){
			cout << num << ' ';
		}
	}
}
