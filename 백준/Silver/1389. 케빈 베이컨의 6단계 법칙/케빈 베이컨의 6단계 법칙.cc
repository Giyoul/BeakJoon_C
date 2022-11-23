/*
	일단 플로이드워샬 알고리즘이 있다.
	얘는 
	for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (i == j) continue;
                else if (MAP[i][k] != 0 && MAP[k][j] != 0){
                    if (MAP[i][j] == 0) MAP[i][j] = MAP[i][k] + MAP[k][j];
                    else MAP[i][j] = Min(MAP[i][j], MAP[i][k] + MAP[k][j]);
                }
            }
        }
    }
	이런 식으로 구현하고, i와 k가 연결되어 있고, k와 j가 연결되어 있다면 값을 비교해서 가장 최단거리로 갱신시켜주는 방식이다.
	참고로 k는 중간점이고, i는 시작점, j는 도착점 역할을 한다.
	
	하지만 BFS로도 쉽게 풀 수 있을 것 같아서 BFS로 풀어보겠다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> map[101];
int Distance[101][101] = {0};
bool visited[101] = {false};

// BFS 함수 정의
void bfs(int N) {
	int minIndex = 1;
	int minDistance;
    // 큐가 빌 때까지 반복	
	for(int j = 1; j <= N; j++){
		queue<int> q;
		q.push(j);
		visited[j] = true; // 첫 노드를 방문 처리
		while (!q.empty()) {
			// 큐에서 하나의 원소를 뽑음
			int x = q.front();
			q.pop();
			// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
			for (int i = 0; i < map[x].size(); i++){
				int y = map[x][i];
				if (!visited[y]) {
					q.push(y);
					visited[y] = true;
					Distance[y][j] = Distance[x][j]+1;	// 거리만큼 ++ ex) 1->4 = 1->2 + 2->4;
					Distance[j][y] = Distance[j][x]+1;	//
				}
			}
		}
		memset(visited, false, 101);
	}
	for(int i = 1; i <= N; i++){
		int SumDistance = 0;
		for(int j = 1; j <= N; j++){
			SumDistance += Distance[i][j];
		}
		if(i == 1){
			minDistance = SumDistance;
		}
		else{
			if(SumDistance < minDistance){
				minIndex = i;
				minDistance = SumDistance;
			}
		}
	}
	cout << minIndex;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M;	// M은 친구 관계 수, N은 사람 수
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++){
		int parent, sibling;
		cin >> parent >> sibling;
		map[parent].push_back(sibling);	// 둘이 이어져 있으므로 둘 다 데이터를 삽입해준다.
		map[sibling].push_back(parent);
		// Distance[parent][sibling] = 1;	// 나중에 생각해보니 어짜피 반복문에서 자기 자신을 거치니 이 문장이 필요가 없다.
		// Distance[sibling][parent] = 1;
	}
	bfs(N);
}