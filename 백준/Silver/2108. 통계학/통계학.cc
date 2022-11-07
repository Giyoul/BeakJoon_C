/*
	class statistics 만들고
	1. an_arithmetic_mean // 산술평균 : N개의 수들의 합을 N으로 나눈 값
	2. midian	// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	3. max_freq	// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
	 ㄴ 단, 추가 조건이 "여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다"
	4. range	// 범위 : N개의 수들 중 최댓값과 최솟값의 차이
	
	class Console에 statistics를 상속받고,
	void run()으로 실행
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>	// 반올림 round를 사용하기 위한 method
#include <utility>
using namespace std;

class Statistics{
public:
	void an_arithmetic_mean(vector<int> vec);
	void midian(vector<int> vec);
	void max_freq(vector<int> vec);
	void range(vector<int> vec);
};

void Statistics::an_arithmetic_mean(vector<int> vec){
	int sum = 0;
	for(int i = 0; i < vec.size(); i++){
		sum+=vec[i];
	}
	int ans = round(sum / (double)vec.size());
	if(ans == -0) ans = 0;
	cout << ans << '\n';
}

void Statistics::midian(vector<int> vec){
	cout << vec[vec.size()/2] << '\n';
}

void Statistics::max_freq(vector<int> vec){
	int count = 0;
	int tmp = vec[0];
	if(vec.size() == 1) cout << vec[0] << '\n';
	else{	
		vector<pair<int, int>> vecPair;	// 빈도수, 수로 pair
		for(int i = 0; i <= vec.size(); i++){	// pair로 새로운 벡터에 저장
			if(tmp == vec[i]){	// 숫자가 중복되면
				count++;
			}
			else{
				vecPair.push_back({count, tmp});
				tmp = vec[i];
				count = 1;
			}
		}
		if(tmp == 0){
			vecPair.push_back({count-1, tmp});
		}
		sort(vecPair.begin(), vecPair.end());	// 점점커지게 소트
		
		int sameindex = vecPair.size()-1;
		int samefreqNum;
		int samefreqSecond;

		samefreqNum = vecPair[sameindex].second;
		samefreqSecond = samefreqNum;
		for(int i = sameindex; i >= 0; i--){
			if(vecPair[i].first == vecPair[i-1].first){
				samefreqSecond = samefreqNum;
				samefreqNum = vecPair[i-1].second;

			}
			else{
				break;
			}
		}
		cout << samefreqSecond << '\n';
	}
}

void Statistics::range(vector<int> vec){
	cout << vec[vec.size()-1] - vec[0] << '\n';
}


class Console : public Statistics{
public:
	void run();
};

void Console::run(){
	vector<int> v;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());	// 정렬
	
	// 통계값 출력
	an_arithmetic_mean(v);
	midian(v);
	max_freq(v);
	range(v);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	Console start;
	start.run();
}
