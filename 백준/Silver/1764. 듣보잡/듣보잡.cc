/*
	
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	map<string, int> m;	// 중복 확인용
	vector<string> v;	// 중복 문자열 저장

	int N, M;	// 보도 N , 듣도 M
	string name;
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){	// 보도 이름 저장
		cin >> name;
		m.insert({name, 1});
	}
	
	for(int i = 0; i < M; i++){	// 듣도 이름을 받고 보도와 비교
		cin >> name;
		if(m[name] == 1){
			v.push_back(name);
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << '\n';
	for(auto it = v.begin(); it != v.end(); it++){
		cout << *it << '\n';
	}
}