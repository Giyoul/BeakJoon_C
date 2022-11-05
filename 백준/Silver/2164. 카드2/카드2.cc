/*
	queue로
	#1 숫자n을 받고
	#2 1, 2, 3, ... n순으로 push
	#3 반복문으로 size가 1이 될때까지
	#4 pop하고, index 0의 수를 push하고 pop 하는 것을 반복한다.
	#5 index 0 의 수를 출력
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	queue<int> q;
	
	int n;
	cin >> n;	// #1
	
	for(int i = 0; i < n; i++){	// #2
		q.push(i+1);
	}
	
	while(q.size() != 1){	// #3
		q.pop();	// #4
		q.push(q.front());
		q.pop();
	}
	cout << q.front();	// #5	
}
