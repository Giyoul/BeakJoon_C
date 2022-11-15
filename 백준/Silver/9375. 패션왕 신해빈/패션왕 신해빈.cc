/*
	한 종류의 의상 수 * 의상 수 * 의상 수 인데
	그냥 안 입은 경우의 수도 의상 수에 포함하고 마지막에 아예 안 입은 경우 하나만 빼주면 된다.
*/

#include <iostream>
#include <map>	// map에는 기본적으로 find 함수가 들어가 있다.
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int testcase, n;
	
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		map<string, int> m;	// map을 초기화 해줘야 하기 때문에 여기에 정의한 것이다.
		cin >> n;
		for(int j = 0; j < n; j++){
			string clothname, part;
			cin >> clothname >> part;
			if(m.find(part) == m.end()){	// iterator처럼 못 찾으면 맨 뒤의 주소를 반환한다.
				m.insert({part, 1});
			}
			else{	// 처음 알게된 사실인데 이런 연산이 가능하다
				m[part]++;
			}
		}
		
		int answer = 1;
		for(auto it = m.begin(); it != m.end(); it++){
			answer *= (it->second + 1);
		}
		cout << answer - 1 << '\n';
	}
}
