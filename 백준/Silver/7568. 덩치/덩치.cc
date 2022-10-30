/*
	#1 이중 for문으로
	A~end 까지 한 쭉 훑어
	등수 = 1;
	
	#2 본인보다 몸무게, 키가 큰 사람을 만나면 등수++
	
	#3 등수 = 1;
*/

#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int height[n], weight[n];
	for(int i = 0; i < n; i++){
		cin >> weight[i] >> height[i];
	}
	
	int ranking = 1;
	for(int i = 0; i < n; i++){	// #1
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			else{
				if(weight[i] < weight[j] && height[i] < height[j]) ranking++;
			}
		}
		cout << ranking << ' ';
		ranking = 1;
	}
}