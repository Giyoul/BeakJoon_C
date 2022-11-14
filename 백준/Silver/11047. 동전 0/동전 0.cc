/*
	어렵게 생각하지 않아도 된다.
	그냥 가장 큰 가치의 화폐부터 가득가득 가져가면 된다.
	
	그리디 알고리즘으로 풀면 테스트 케이스가 2 2700에 300 1000이면 4라는 쌩뚱맞은 값을 만들어낸다.
	300 * 9 여서 9이어야 하지만, 1000 * 2, 300 * 2 여서 4를 출력하는 것이다.
	하지만 이 문제의 테스트 케이스에서는 화폐의 종류가 많은가보다 오류가 안나는걸 보니.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> v;
	
	int N, K;
	int charge, count = 0;
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++){
		cin >> charge;
		v.push_back(charge);
	}
	sort(v.begin(), v.end(), greater<int>());	// 큰 값부터 내림차순으로 정렬
	
	for(int i = 0; i < N; i++){
		while(v[i] <= K){
			K-=v[i];
			count++;			
		}
	}
	cout << count;
}