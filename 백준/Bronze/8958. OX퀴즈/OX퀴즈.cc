#include <iostream>
#include <string>
using namespace std;

int OXSUM(string& s){
	int sum = 0;
	int count = 0;
	
	int size = s.length();
	for(int i = 0; i < size; i++){
		if(s[i] == 'O') count++;
		else count = 0;
		sum += count;
	}
	return sum;
}

int main(){
	int num;
	cin >> num;
	cin.ignore();
	for(int i = 0; i < num; i++){
		string str;
		getline(cin, str);
		cout << OXSUM(str) << '\n';
	}
}