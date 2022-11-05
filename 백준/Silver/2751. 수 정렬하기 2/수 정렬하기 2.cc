/*
	algorithm의 sort는 O(nlogn);
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	int* num = new int [n];
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	sort(num, num + n);
	for(int i = 0; i < n; i++){
		cout << num[i] << '\n';
	}
	
}
