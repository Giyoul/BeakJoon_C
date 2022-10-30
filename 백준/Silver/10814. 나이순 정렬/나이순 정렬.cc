/*
	stable sort 이용한 정렬
	
	pair을 사용하면 map처럼 두 자료를 묶어서 사용할 수 있다.
	pair에 sort를 사용하면 첫번째를 비교하고, 둘이 같으면 두번째를 비교한다.
	접근은 map처럼 .first, .second를 사용하면 된다.
	
	받은 후 vector에 push_back해주고
	stable sort 해준다.
	
	
		stabel sort >> 본래 데이터의 입력 순서 그대로 정렬
		 ㄴ 같은 데이터가 있으면 먼저 들어온 데이터 기준으로 소트한다.
	
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool comp(pair<int,string> data1, pair<int,string> data2){	// 비교구문 작성
	return data1.first < data2.first;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	pair<int, string> index;
	vector<pair<int, string>> member;
	for(int i = 0; i < n; i++){
		cin >> index.first >> index.second;
		member.push_back(index);
	}
	stable_sort(member.begin(), member.end(), comp);	// 그냥 sort 하면 같은 나이일 경우 이름의 사전순으로 정렬하므로 stable을 사용해준다.
	
	for(auto it = member.begin(); it != member.end(); it++){
		cout << it->first << ' ' << it->second << '\n';
	}
}