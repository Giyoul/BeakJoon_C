/*
	map으로 pair 저장하고 그냥 출력하면 될듯
	아싸 꽁이다
*/
#include <iostream>
#include <map>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	map<string, string> m;
	
	int N, M;
	string site, password;
	
	cin >> N >> M;	
	for(int i = 0; i < N; i++){
		cin >> site >> password;
		m.insert({site, password});
	}
	
	for(int i = 0; i < M; i++){
		cin >> site;
		cout << m[site] << '\n';
	}
}