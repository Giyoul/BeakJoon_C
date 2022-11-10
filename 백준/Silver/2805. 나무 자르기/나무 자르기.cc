/*
	binary search를 사용해서 풀면 쉽다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int> v, long long target){
	int start = 0;
	int end = v[0];	// 가장 큰 높이를 end에 저장
	long long answer;
	
	while(start <= end){
		long long sum = 0;
		int midHeight = (start + end) / 2;
		
		int i = 0;
		while(midHeight < v[i]){
			sum+=(v[i]-midHeight);	// 자른 만큼 sum에 더해줌.
			i++;
		}
		if(sum == target){
			answer = midHeight;
			return answer;
		}
		else if(sum < target){	// 원하는 양보다 덜 자를 경우에는 정답이 아니므로 midHeight가 answer가 될 수 없다.
			end = midHeight-1;
		}
		else{
			start = midHeight+1;
			answer = midHeight;
		}
	}
	return answer;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	long long targetSize;
	cin >> n >> targetSize;
	vector<int> v;
	
	for(int i = 0; i < n; i++){
		int height;
		cin >> height;
		v.push_back(height);
	}
	
	sort(v.begin(), v.end(), greater<int>());	// 내림차순으로 정렬
		
	cout << BinarySearch(v, targetSize);
}
