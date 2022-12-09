/*
	1012 유기농 배추 문제를 조금만 변형하면 쉽게 풀 수 있다.

	DFS로 탐색하고, count를 계속 해주다가, 끝에 도달하면 배열에 저장하면 된다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[52][52] = {0};	// 아무것도 없는 곳을 0으로 마킹	(테두리는 0으로 둘러놓을거다)
vector<int> v;	// v 안에 단지 건물의 개수를 저장

void DFS(int y, int x, int& count){	// recursion
	count++;
	arr[y][x] = 0;
	if(arr[y-1][x] == 1){	// 위쪽 탐색
		DFS(y-1, x, count);
	}
	if(arr[y][x+1] == 1){	// 오른쪽 탐색
		DFS(y, x+1, count);
	}
	if(arr[y+1][x] == 1){	// 아래쪽 탐색
		DFS(y+1, x, count);
	}
	if(arr[y][x-1] == 1){	// 왼쪽 탐색
		DFS(y, x-1, count);
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int testcase, width, height, quantity, xpos, ypos;
	
	cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		string str;
		cin >> str;

		for(int j = 1; j <= str.size(); j++){
			arr[i][j] = str[j-1] - '0';
		}
	}
	for(int j = 1; j <= testcase; j++){	// 밭을 탐색한다.
		for(int k = 1; k <= testcase; k++){
			if(arr[j][k] == 1){
				int count = 0;
				DFS(j, k, count);	// x, y좌표까지 보내줌
				v.push_back(count);
			}
			// cout << arr[j][k] << ' ';
		}
		// cout << '\n';
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(auto it = v.begin(); it != v.end(); it++){
		cout << *it << '\n';
	}
}
