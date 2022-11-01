/*
	stack을 이용해서 해결
	(나 [가 나올때마다 stack에 push해주고,  )나 ]가 나오면 stack의 top에 각각 ( 과 [가 있는지 확인하고 pop해준다.
	없으면 false이다.
*/


#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while(1){
		stack<char> s;	// shile 안쪽에 넣어줘서 한줄마다 stack을 초기화 해준다.
		string str;
		getline(cin, str);	// 몇줄을 한번에 써도 한 줄씩 str에 받는다.
		int ans = 0;	// 0 이면 정답, -1 이면 오답
		
		if(str.length() == 1 && str[0] == '.'){	// 모든 문자열의 마지막
			break;
		}
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '(' || str[i] == '['){
				s.push(str[i]);
			}
			else if(str[i] == ')'){
				if(s.empty() || s.top() != '(') ans = -1;
				else s.pop();
			}
			else if(str[i] == ']'){
				if(s.empty() || s.top() != '[') ans = -1;
				else s.pop();
			}
		}
		if(ans == 0 && s.empty()){
			cout << "yes" << '\n';
		}
		else{
			cout << "no" << '\n';
		}
	}
	return 0;
}
