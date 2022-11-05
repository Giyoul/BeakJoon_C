/*
	N+M의 값이 2의 배수인 경우가 B인지 W인지에 대해 기준을 잡고 case1 case2로 만들면 쉽게 비교가 가능하다.
	
*/

#include <iostream>
using namespace std;

char arr[51][51];

int white(int x, int y){
	int result = 0;
	for(int i = x; i < x+8; i++){
		for(int j = y; j < y+8; j++){
			if((i+j)%2 == 0){
				if(arr[i][j] == 'B'){
					result++;
				}
			}
			else{
				if(arr[i][j] == 'W'){
					result++;
				}
			}
		}
	}
	return result;
}

int black(int x, int y){
	int result = 0;
	for(int i = x; i < x+8; i++){
		for(int j = y; j < y+8; j++){
			if((i+j)%2 == 0){
				if(arr[i][j] == 'W'){
					result++;
				}
			}
			else{
				if(arr[i][j] == 'B'){
					result++;
				}
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	int result = 64;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];

	int tmpwhite, tmpblack;
	for(int i = 0; i <= n - 8; i++){
		for(int j = 0; j <= m - 8; j++) {
			tmpwhite = white(i, j);
			tmpblack = black(i, j);
			if(tmpwhite < tmpblack){
				if(tmpwhite < result){
					result = tmpwhite;
				}
			}
			else{
				if(tmpblack < result){
					result = tmpblack;
				}
			}
		}
	}
	cout << result;
}
