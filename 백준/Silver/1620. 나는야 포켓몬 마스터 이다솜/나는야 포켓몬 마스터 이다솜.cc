/*
	
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	map<string, int> m;	// map에는 string, int를 저장해서 포켓몬 이름을 부르면 번호를 말하도록 할 때 쓰고
	vector<string> v; // vector에는 index(포켓몬 도감 번호)를 부르면 그 포켓몬의 이름을 부르도록 사용한다
	
	int N, M;	// N은 입력받을 포켓몬 개수, M은 출력할 이름 || 번호 개수
	string name; // 포켓몬 이름 입력
	string callPOOKI;	// 포켓몬 부르기
		
	cin >> N >> M;
	
	// 포켓몬 도감 번호는 index + 1이다.
	for(int i = 0; i < N; i++){	// 포켓몬 도감 정보 입력
		cin >> name;
		m.insert({name, i});
		v.push_back(name);
	}
	
	for(int i = 0; i < M; i++){	// 포켓몬 이름 부르기
		cin >> callPOOKI;	// int나 string 둘 다 들어올 수 있으니 테스트를 진행해야 한다.
		if(isdigit(callPOOKI[0])){	// 도감 번호를 불렀으면
			int intcall = stoi(callPOOKI);	// string을 int로 바꿔주기
			cout << v[intcall-1] << '\n';	// 포켓몬 도감 번호는 index + 1이므로 -1을 해준다.
		}
		else{	// 포켓몬 이름을 불렀으면
			cout << m[callPOOKI] + 1 << '\n';	// map에 저장된 포켓몬이름(.first)의 도감 번호(.second)를 출력한다.
		}
	}	
}