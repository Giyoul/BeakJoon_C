/*
	dp이긴 한 것 같은데... 점화식... 살려ㅈ..
	일단 0 < n < 11이고 1, 2, 3으로만 나타내야 하기 때문에 아래와 같은 케이스들이 만들어지는데,
	
	n	/	값
	1		1
	2		2
	3		4
	4		7
	5		13
	6		24
	7		44
	
	일단 n은 n보다 아래 케이스의 것들을 다 더한 값인 것 같다.
	n이 3보다 클 때에는
	 점화식 >>
	dp[n] = dp[n-1] + d[n-2] + dp[n-3]];
	
*/

#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int dp[11] = {0, 1, 2, 4};
	int n, num;	// 2번째까지 다 더한 값
	
	cin >> n;
	
	for(int i = 4; i <= 10; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	
	for(int j = 0; j < n; j++){
		cin >> num;
		cout << dp[num] << '\n';
	}
}
