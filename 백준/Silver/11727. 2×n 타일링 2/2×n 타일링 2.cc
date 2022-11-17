	/*
		dp문제이고, 점화식이 도저히 답이 안나와서 조금 찾아봤다.
		n이 1, 2일때는 맞았는데 3일 때 1x2을 두 개 더하는 것을 안 세서 값이 이상하게 나왔었다.
		
		arr[n] = arr[n-1] + arr[n-2] * 2;이다.
		
		>> 힌트를 보니 arr를 안쓰고 dp[]로 쓰더라
		이제 dp문제의 arr는 dp로 쓰는게 나을 듯.		
	*/

	#include <iostream>
	using namespace std;

	int main(){
		ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

		int num;
		int dp[1001] = {0, 1, 3};
		
		cin >> num;
		for(int i = 3; i <= num; i++){
			dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;	// 연산 과정에서 %10007을 해주지 않으면 int 범위를 넘어설 수 있다.
		}
		cout << dp[num];
	}
