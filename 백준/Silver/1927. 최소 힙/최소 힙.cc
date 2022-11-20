/*
	
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	priority_queue<int, vector<int>, greater<int>> pq;	// 오름차순으로 정렬된 heap
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 0){
			if(pq.empty()) cout << 0 << '\n';
			else{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else{
			pq.push(x);
		}
	}
}
