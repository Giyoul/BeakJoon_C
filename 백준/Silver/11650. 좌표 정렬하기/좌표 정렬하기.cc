/*
	pair에 sort를 사용하면, 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	vector<pair<int, int>> vec;
	
	int num1, num2;	
	
	for(int i = 0; i < n; i++){
		cin >> num1 >> num2;
		vec.push_back({num1, num2});
	}
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < n; i++){
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
	
}
