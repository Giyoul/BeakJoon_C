/*
	BFS로 푸는 문제다.
	일단, 가장 적게 가는 경우에 수는 많으므로, 그냥 x+1, x-1, x*2의 노드를 방문했는지 확인하고 방문하지 않았다면 들어가고
	time를 현 위치보다 1 높게 설정해주면 된다.
	어짜피 재방문하는 곳이 현재 시간보다 더 오래 걸렸을 수는 절대 없다.
*/

#include <iostream>
#include <queue>
using namespace std;

int Spendtime[100001] = {0};
bool visited[100001] = {false};

// BFS 함수 정의
void bfs(int me, int young){
    // 큐가 빌 때까지 반복	
	queue<int> q;
	
	q.push(me);
	visited[me] = true; // 첫 노드를 방문 처리
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if(x == young){	// 동생을 찾으면, 지금 나의 거리에서 +1 해준것을 출력.
			cout << Spendtime[x];
			break;
		}
		if(x+1 <= 100000 && !visited[x+1]){
			q.push(x+1);
			visited[x+1] = true;
			Spendtime[x+1] = Spendtime[x]+1;
		}
		if(x-1 >= 0 && !visited[x-1]){
			q.push(x-1);
			visited[x-1] = true;
			Spendtime[x-1] = Spendtime[x]+1;	
		}
		if(2*x <= 100000 && !visited[x*2]){
			q.push(x*2);
			visited[x*2] = true;
			Spendtime[x*2] = Spendtime[x]+1;
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, K;	// M은 내 위치, N은 동생 위치
	cin >> N >> K;
	bfs(N, K);
}

/*
	이 문제를 풀고 다른 사람들의 문제 풀이를 보니, queue에 pair로 데이터를 저장했다.
	if(x+1 >=0 && x+1<100001){
		if(!visit[x+1] ){
			visit[x + 1] = true;
			q.push(make_pair(x + 1, cnt + 1));
		}
	}
	대충 이런식인데,
	이를 보고나니	예전에 플루이드로샬 문제를 풀 때에도 pair로 queue에 넣어서 count를 출력해도 되는거였다는 것을 깨달았다.
*/