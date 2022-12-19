/*
	BFS를 사용하는 문제이다.

	#1 queue에 들어가는 값은 tuple로 {xpos, ypos, date}를 저장해준다.
		tuple은 tuple을 include 하여 사용하고,
		 get<0>(q.front()) 이런식으로 호출,
		 q.push(make_tuple(x, y, z)); 이런 식으로 사용한다.

	#3 xpos, ypos의 사방을 서치하고, 0인 값이 있으면, 해당 좌표의 {xpos, ypos, date+1}을 저장해 준다.
	#4 물론 다녀간 좌표는 -1로 바꿔준다.
	#5 시작 지점에서 date를 비교하고, maxdate보다 date가 크면 maxdate를 date로 대체해준다.

	#2 BFS가 시작되는 queue에는 전 좌표를 탐색하고 1이 들어가 있는 좌표를 전부 push 해주고 시작해야 한다.
	
	#6 queue에 더 이상 값이 없으면 전 좌표를 한번 더 서치해야 하는데, 0인 값이 남아 있으면 -1을 출력하고 없으면 date를 출력한다.
*/

#include <iostream>
#include <tuple>
#include <queue>
#include <string.h>
using namespace std;

int map[1002][1002];	// 테두리는 -1로 둘러주어서, 정해진 범위 밖으로 서칭하는 경우가 없도록 방지한다.
int maxdate = 0;
queue<tuple<int, int, int>> q;

void BFS(){
	while(!q.empty()){
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int date = get<2>(q.front());

		if(maxdate < date) maxdate = date;	// #5
		// #3
		if(map[y+1][x] == 0){
			q.push({y+1, x, date+1});
			map[y+1][x] = -1;	// #4
		}
		if(map[y][x+1] == 0){
			q.push({y, x+1, date+1});
			map[y][x+1] = -1;	// #4
		}
		if(map[y-1][x] == 0){
			q.push({y-1, x, date+1});
			map[y-1][x] = -1;	// #4
		}
		if(map[y][x-1] == 0){
			q.push({y, x-1, date+1});
			map[y][x-1] = -1;	// #4
		}
		q.pop();
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 2차원 배열을 모두 -1로 초기화 해준다.
	memset(map, -1, sizeof(map));

	int x, y, flag = 0;
	cin >> x >> y;
	// #1, #2
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			cin >> map[i+1][j+1];
			if(map[i+1][j+1] == 1){
				q.push({i+1, j+1, 0});
			}
		}
	}
	BFS();

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(map[i+1][j+1] == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 1) break;
	}

	if(flag == 1) cout << -1;
	else cout << maxdate;
}