/*
	1260 DFS BFS 문제 코드를 이용했다.

	BFS 문제로 map으로 갈 수 있는 위치를 체크하고, Distance로 현재 위치의 거리를 체크, check로 왔던 길인지 체크해주면 된다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int Map[102][102] = {0};	// 데이터가 들어가는 지도, 0으로 초기화 한 이유는, 원래 맵의 최대 크기는 100, 100 이지만, 102, 102로 선언함으로써 가장 끄생이를 벽으로 감싸기 위함
int Distance[102][102] = {0};	// 거리 체크
bool check[102][102] = {false};

void BFS(int posx, int posy){
	queue<pair<int, int>> q;
	Distance[1][1] = 1;
	check[1][1] = true;
	q.push({1, 1});
	while(!q.empty()){
		int currentY = q.front().first;
		int currentX = q.front().second;
		q.pop();

		if(!check[currentY][currentX+1] && Map[currentY][currentX+1] == 1){		// 오른쪽 체크
			check[currentY][currentX+1] = true;
			Distance[currentY][currentX+1] = Distance[currentY][currentX] + 1;
			q.push({currentY, currentX+1});
		}
		if(!check[currentY+1][currentX] && Map[currentY+1][currentX] == 1){		// 아래쪽 체크
			check[currentY+1][currentX] = true;
			Distance[currentY+1][currentX] = Distance[currentY][currentX] + 1;
			q.push({currentY+1, currentX});
		}
		if(!check[currentY-1][currentX] && Map[currentY-1][currentX] == 1){		// 위쪽 체크
			check[currentY-1][currentX] = true;
			Distance[currentY-1][currentX] = Distance[currentY][currentX] + 1;
			q.push({currentY-1, currentX});
		}
		if(!check[currentY][currentX-1] && Map[currentY][currentX-1] == 1){		// 왼쪽 체크
			check[currentY][currentX-1] = true;
			Distance[currentY][currentX-1] = Distance[currentY][currentX] + 1;
			q.push({currentY, currentX-1});
		}
	}
	cout << Distance[posy][posx];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	
	int posx, posy;
	cin >> posy >> posx;
	
	for(int i = 1; i <= posy; i++){
		string str;
		cin >> str;
		for(int j = 1; j <= str.length(); j++){
			Map[i][j] = str[j-1] - '0';
		}
	}

	BFS(posx, posy);	
}

