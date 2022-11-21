/*
	그냥 recursion 하기
*/

#include <iostream>
using namespace std;

void check(int color[], int map[][129], int starty, int startx, int size){
	int tmp = map[starty][startx];
	int flag = 1;
	for(int i = starty; i < starty + size; i++){
		for(int j = startx; j < startx + size; j++){
			if(tmp != map[i][j]){
				flag = 0;
				break;
			}
		}
		if(flag == 0) break;
	}
	if(flag == 0){
		for(int i = starty; i < starty + size; i += size/2){
			for(int j = startx; j < startx + size; j += size/2){
				check(color, map, i, j, size/2);
			}
		}
	}
	else{
		color[tmp]++;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int map[129][129];
	int n, divide = 1;	// while는 0, blue는 1로 표현, divide는 종이를 몇 번 나누었는지를 나타냄
	int color[2] = {0};
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	
	check(color, map, 0, 0, n);
	cout << color[0] << '\n' << color[1];
}