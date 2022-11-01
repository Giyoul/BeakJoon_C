#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while(1){
		string str;
		getline(cin, str);
		if(str[0] == '0') break;
		int start = 0;
		int end = str.size() - 1;
		int flag = 1;
		while(start != end){
			if(start > end){
				break;
			}
			if(str[start++] != str[end--]){
				flag = 0;
				break;
			}
		}
		if(flag == 1) cout << "yes\n";
		else cout << "no\n";
	}	
}


/*
	algorithm의 reverse를 사용해도 된다.
*/