#include <iostream>
#include <algorithm>
using namespace std;

bool strcompare(string st1, string st2){
	if(st1.length() == st2.length()){
		return st1 < st2;
	}
	return st1.length() < st2.length();
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	string str[n];
	for(int i = 0; i < n; i++){	
		cin >> str[i];
	}
	
	sort(str, str+n, strcompare);
	
	for(int i = 0; i < n; i++){
		if(str[i] == str[i+1]) continue;
		cout << str[i] << '\n';
	}
	
}