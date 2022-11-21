/*
	수를 벡터에 받고, sort 해준 다음, 중복 지우고, map에 넣어주고 출력해준다. 가 나의 솔루션
	인데 문제를 풀다보니 쓰레기값 버리는 것에 시간이 너무 많이 소모되었다.
	그래서 솔루션을 찾아보니, unique라는 놈이 있다고 한다.
	unique는 범위 안에서 종복되는 값들을 쓰레기 값으로 처리하여 배열 뒤쪽으로 보내고, 쓰레기 값들이 이동한 좌표의 가장 처음 좌표를 리턴한다.
	이를 이용해서 erase하면 쉽게 풀 수 있다.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> v;
	map<int, int> m;
	int N;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	vector<int> sortv = v;
	sort(sortv.begin(), sortv.end());
	sortv.erase(unique(sortv.begin(), sortv.end()), sortv.end());
	
	for(int i = 0; i < sortv.size(); i++){
		m[sortv[i]] = i;
	}
	
	for(int i = 0; i < v.size(); i++){
		cout << m[v[i]] << ' ';
	}
}