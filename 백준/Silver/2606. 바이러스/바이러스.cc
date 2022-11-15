/*
	DFS라는 놈이 있다
	깊이 우선 탐색이란 놈인데
	트리에서 parent node부터 탐색하면서 아래로 아래로 내려가는 거다.
	근데 이제 recursive로 들어가주는건데, 이게 이 문제같이 1이 root node로 정해져 있으니 사용이 가능한 것 같다.
	recursive라 속도가 느릴 것 같긴 한디... 일단 데이터의 맥시멈이 100이니까 딱히 의미는 없을 것 같긴 하다.
*/

#include <iostream>
#include <vector>
using namespace std;

// recursive를 사용해야 하기 때문에 함수로 선언한다.
void DFS(int n, int &count, bool check[], vector<int> v[]){
	check[n] = true;	// 일단 recursive를 해도 본인은 연결되어 있다는게 증명이 된 것이므로 true 해준다.
	for(int i = 0; i < v[n].size(); i++){
		int linknum = v[n][i];	// 가지 하나씩 탐색하여 recur로 처리
		
		// cout << '[' << n << " -> " << linknum << "]\n"; 테스트 해보고 싶다면 이거
		
		if(!check[linknum]){	// 만약 가지노드가 한번도 탐색하지 않은 노드라면 (한번도 거쳐가지 않은 노드라면)
			DFS(linknum, count, check, v);	// 그 노드로 가서 체크를 해준다.
			count++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<int> v[101];	// 이런식으로 선언하면 v[0].push_back(1) 이런식으로 쓰고, v[0][0]; >> 1로 저장이 가능하다.
	bool check[101];	// 연결이 되어 있는지를 체크하는 선언
	int num, linkpair, parent, sibling, count = 0;
	
	cin >> num >> linkpair;
	
	for(int i = 0; i < linkpair; i++){
		cin >> parent >> sibling;
		v[parent].push_back(sibling);
		v[sibling].push_back(parent);
	}
	
	DFS(1, count, check, v);
	cout << count;
}
