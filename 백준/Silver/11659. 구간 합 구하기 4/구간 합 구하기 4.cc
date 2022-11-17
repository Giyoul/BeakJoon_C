/*
	dp문제다.
*/

#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int line, testcase, fromIndex, toIndex;
	int arr[100001] = {0, };
	
	cin >> line >> testcase;
	
	for(int i = 0; i < line; i++){
		int num;
		cin >> num;
		arr[i+1] = arr[i] + num;
	}
	
	for(int i = 0; i < testcase; i++){
		cin >> fromIndex >> toIndex;
		cout << arr[toIndex] - arr[fromIndex - 1] << '\n';
	}
}
