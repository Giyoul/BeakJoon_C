/*
	DFS 사용해서 한 노드에서 사방위를 검사하고 타고 들어가서 데이터가 1이 저장되어 있으면(배추가 심어진 곳은 1로 표기한다.) 그 좌표를 true로 마킹하고 recursion
	그래서 for문으로 전체 탐색하는데, true로 마킹된 곳은 이미 다녀간 곳이므로 count하지 않고, false 되어있는 곳은 count++ 해주고, 위의 recursion을 반복한다.
	
	아니면 마킹을 1로 저장되어 있는 것을 0으로 바꿔줘도 된다. 이게 더 쉬울 듯.
*/

#include <iostream>
using namespace std;

void DFS(int arr[][52], int y, int x){	// recursion
	arr[y][x] = 0;
	if(arr[y-1][x] == 1){	// 위쪽 탐색
		DFS(arr, y-1, x);
	}
	if(arr[y][x+1] == 1){	// 오른쪽 탐색
		DFS(arr, y, x+1);
	}
	if(arr[y+1][x] == 1){	// 아래쪽 탐색
		DFS(arr, y+1, x);
	}
	if(arr[y][x-1] == 1){	// 왼쪽 탐색
		DFS(arr, y, x-1);
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int testcase, width, height, quantity, xpos, ypos;
	
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		int arr[52][52] = {0};	// 아무것도 없는 곳을 0으로 마킹	(테두리는 0으로 둘러놓을거다)
		int count = 0;
		cin >> width >> height >> quantity;
		for(int j = 1; j <= quantity; j++){
			cin >> xpos >> ypos;
			arr[ypos + 1][xpos + 1] = 1;	// 배추가 심어진 좌표를 1로 마킹
		}
		
		for(int j = 1; j <= height; j++){	// 밭을 탐색한다.
			for(int k = 1; k <= width; k++){
				if(arr[j][k] == 1){
					count++;
					DFS(arr, j, k);	// x, y좌표까지 보내줌
				}
				// cout << arr[j][k] << ' ';
			}
			// cout << '\n';
		}
		cout << count << '\n';
	}
}
