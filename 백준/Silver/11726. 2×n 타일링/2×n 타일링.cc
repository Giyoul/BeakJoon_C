	/*
		dp문제다.
		점화식이 일단,
		N	/	가짓수
		1		1
		2		2
		3		3
		4		5
		5		8

		그냥 arr[n] = arr[n-1] + arr[n-2]이다
		쉬운 문제다.
	*/

	#include <iostream>
	using namespace std;

	int main(){
		ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

		int n;
		long long arr[1001] = {1, 2};
		cin >> n;


		for(int i = 2; i <= n - 1; i++){
			arr[i] = (arr[i-1] + arr[i-2]) % 10007;
		}
		cout << arr[n - 1];
	}
