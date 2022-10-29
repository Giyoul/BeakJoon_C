#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int isend = 0;	
	string str;
	
	for(int i = 0; i < n; i++){
		queue<char> q;
		cin >> str;
		int size = str.length();
		for(int j = 0; j < size; j++){
			if(str[j] == '('){
				q.push(str[j]);
			}
			else if(str[j] == ')'){
				if(q.empty()){
					isend = -1;
					break;
				}
				else{
					q.pop();
				}
			}
		}
		if(!q.empty() || isend == -1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
		isend = 0;
	}	
}
