/*
	수의 개수가 메모리보다 많아서 메모리를 다 잡아먹는 현상이다.
	이런 경우에 그냥 수를 세주고 그 수많큼 프린트 해주는 것이 낫다.
	수의 개수는 ≤ 10,000,000이지만,
	수의 범위는 ≤ 10,000 이기 떄문이다.
*/

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int arr[10001] = {0};
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		arr[num]++;
	}

	for(int i = 0; i < 10001; i++){
		for(int j = 0; j < arr[i]; j++){
			cout << i << '\n';	
		}
	}
}
