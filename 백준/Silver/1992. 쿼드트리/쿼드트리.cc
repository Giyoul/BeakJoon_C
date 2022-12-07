/*
	일단 비교 문자에 처음 좌표의 것을 넣고, 비교해보다가, 다르면 recursion으로 네 좌표 나눠서 들어가고,
	맞으면 그냥 출력

	전형적인 분할정복 문제이다.
*/

// 1074번 문제 "Z" 코드를 변형했다.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int MAP[65][65];


void check(int startx, int starty, int size){
	int checkNum = MAP[starty][startx];
	int flag = 0;	// 0은 압축으로 표현이 가능한 상태, 1은 분할하여 검사해야 하는 상태
	
	for(int i = starty; i < starty + size; i++){
		for(int j = startx; j < startx + size; j++){
			if(checkNum != MAP[i][j]){
				flag = 1;
				break;
			}
		}
		if(flag == 1) break;
	}

	if(flag == 1){
		cout << '(';
        check(startx, starty, size / 2);
        check(startx + size / 2, starty, size / 2);
        check(startx, starty + size / 2,size / 2);
        check(startx + size / 2, starty + size / 2, size / 2);
		cout << ')';
    }
	else{
		cout << checkNum;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;

	cin >> N;
    for (int i = 0; i < N; i++){
        string str;	// 문자열로 받고 각 글씨를 int형으로 바꿔준다.
		cin >> str;
		int length = str.length();
        for (int j = 0; j < str.length(); j++){
            MAP[i][j] = str[j] - '0';
        }
    }

	check(0, 0, N);
}