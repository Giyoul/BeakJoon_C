/*
	바이러스 문제와 상당히 비슷하다.
	그 DFS 사용하면 됨
*/

#include <iostream>
#include <vector>
using namespace std;

bool DFS(int n, bool check[], vector<int> v[]){
	if(check[n] == false){
		check[n] = true;	// 일단 recursive를 해도 본인은 연결되어 있다는게 증명이 된 것이므로 true 해준다.
		for(int i = 0; i < v[n].size(); i++){
			int linknum = v[n][i];

			// cout << '[' << n << " -> " << linknum << "]\n"; 테스트

			if(!check[linknum]){	// 만약 가지노드가 한번도 탐색하지 않은 노드라면 (한번도 거쳐가지 않은 노드라면)
				DFS(linknum, check, v);	// 그 노드로 가서 체크를 해준다.
			}
		}
		return true;
	}
	else{
		return false;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<int> v[1001];
	bool check[1001] = {false};
	int num, linkpair, parent, sibling, count = 0;
	
	cin >> num >> linkpair;
	
	for(int i = 0; i < linkpair; i++){
		cin >> parent >> sibling;
		v[parent].push_back(sibling);
		v[sibling].push_back(parent);
	}
	
	for(int i = 0; i < num; i++){
		if(DFS(i+1, check, v)){
			count++;
		}
	}
	cout << count;
}
