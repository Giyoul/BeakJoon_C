/*
	DFS는 recursion으로
	BFS는 queue로 구현한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

void DFS(int n, bool check[], vector<int> v[]){
	check[n] = true;
	cout << n << ' ';
	for(int i = 0; i < v[n].size(); i++){
		int linknum = v[n][i];
		
		// cout << '[' << n << " -> " << linknum << "]\n"; 테스트 해보고 싶다면 이거
		
		if(!check[linknum]){	// 만약 가지노드가 한번도 탐색하지 않은 노드라면 (한번도 거쳐가지 않은 노드라면)
			DFS(linknum, check, v);	// 그 노드로 가서 체크를 해준다.
		}
	}	
}

void BFS(int n, bool check[], vector<int> v[]){
	queue<int> q;
	check[n] = true;
	q.push(n);
	while(!q.empty()){
		n = q.front();
		cout << n << ' ';
		q.pop();
		for(int i = 0; i < v[n].size(); i++){
			if(!check[v[n][i]]){
				q.push(v[n][i]);
				check[v[n][i]] = true;
			}
		}
	}	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<int> v[1002];	// 이런식으로 선언하면 v[0].push_back(1) 이런식으로 쓰고, v[0][0]; >> 1로 저장이 가능하다.	// index1부터 사용하기 때문에 1002로 선언했다.
	bool check[1002] = {false};	// 연결이 되어 있는지를 체크하는 선언
	int num, linkpair, start, parent, sibling;
	
	cin >> num >> linkpair >> start;
	
	for(int i = 1; i <= linkpair; i++){
		cin >> parent >> sibling;
		v[parent].push_back(sibling);
		v[sibling].push_back(parent);
	}
	for(int i = 1; i <= num; i++){
		sort(v[i].begin(), v[i].end());	// 정점 번호가 여러개인 경우에는 작은 것부터 방문
	}
	
	DFS(start, check, v);
	cout << '\n';
	memset(check, false, sizeof(check));	// 처음에는 그냥 다시 선언했는데 bool check = {false}; >> 이런것도 있더라 memset은 초기화해주는 함수
	BFS(start, check, v);	
}
