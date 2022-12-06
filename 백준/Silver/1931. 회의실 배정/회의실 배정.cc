/*
	끝나는 시간 기준으로 정렬
	second <= first -> 회의 끝나는 시간과 시작하는 시간을 비교했을 때, 시작하는 시간이 끝나는 시간보다 뒤에 있으면 count++
	이는 끝나는 시간을 기준으로 이미 정렬되어 있으므로, 1번만 반복해도 정답이 나올것이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	int count = 1;
	vector<pair<int, int>> v;

	cin >> N;

	for(int i = 0; i < N; i++){
		int start, end;
		cin >> start >> end;
		v.push_back({end, start});
	}

	sort(v.begin(), v.end());

	int endTime = v[0].first;	// first is the time that meeting ended
	for(int i = 1; i < N; i++){
		if(endTime <= v[i].second){
			count++;
			endTime = v[i].first;
		}
	}
	cout << count;
}
