/*
	
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	stack<int> s;
	vector<char> v;	// vector가 아닌 문자열로 할 경우 +와 -가 얼마나 들어갈 지 모르기 때문에 선언이 복잡해진다.
	
	int n;
	cin >> n;
	int count = 0;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		while(count < num){	// 입력하는 값 까지 push
			s.push(count+1);
			count++;
			v.push_back('+');
		}
		if(num == s.top()){	// 가장 위의 값과 찾는 값 비교
			s.pop();
			v.push_back('-');
		}
		else{	// 불가한 수열일 경우 No
			cout << "NO";
			v.clear();	// 불가능 할 경우 벡터에 들어간 +와 -를 모두 지워 출력되지 않도록 한다.
			break;
		}
	}
	if(!v.empty()){	// 벡터가 비어있지 않은 경우
		for(auto it = v.begin(); it != v.end(); it++){
			cout << *it << '\n';
		}
	}
	
}
