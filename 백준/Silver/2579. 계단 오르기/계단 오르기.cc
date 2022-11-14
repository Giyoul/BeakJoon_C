/*
	dp 문제이다. 다이나믹 프로그래밍
	점화식이 골이 많이 아프다ㅠㅠ
	
	결국은 2계단 전 까지의 최대와 현재 계단을 밟기 VS 3계단 전까지의 최대와 1계단전 + 현재 계단 밟기 두 개의 케이스로 나뉘므로
	점화식이
	dp[n] = dp[n-2] + arr[n]
	dp[n] = dp[n-3] + arr[n-1] + arr[n]
	이다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, score;
	
	cin >> n;
	int arr[n + 1] = {0};	// 계단의 점수를 저장하는 배열, index0은 땅바닥으로 0점이다.
	int dp[n + 1] = {0};	// max의 값을 저장하는 배열
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];	// 1번째 계단과 2번째 계단의 최대는 이변이 없다.
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	
	for(int i = 4; i <= n; i++){
		dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
	}
	cout << dp[n];
	
}