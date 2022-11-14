/*
	그리디 알고리즘으로 오름차순으로 정렬된 vector의 값을 그냥 다 더하면 되겠다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> v;
	
	int N, time;
	int sum = 0;
	int increase = 0;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> time;
		v.push_back(time);
	}
	sort(v.begin(), v.end());	// 오름차순 정렬
	
	for(int i = 0; i < N; i++){
		increase += v[i];
		sum += increase;
	}
	
	cout << sum;
}