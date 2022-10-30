#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	
	for(int i = 0; i < n; i++){
		queue<pair<int, int>> q;	// 현재 위치 인덱스와 중요도를 둘 다 답기 위해 pair 선언
		int size, index, priority = 0;
		cin >> size >> index;
		int sequence[size];		// 순서대로 정렬할 배열 선언
		for(int j = 0; j < size; j++){
			int num;
			cin >> num;
			sequence[j] = num;
			q.push({j, num});	// pair로 넣어주기
		}
		sort(sequence, sequence + size, compare);
		
		while(!q.empty()){
			int ind_first = q.front().first;
			int ind_second = q.front().second;
			q.pop();	// 비교할 대상이 복사됐으므로 pop해준다.
			if(sequence[priority] == ind_second){
				priority++;
				if(ind_first == index){
					cout << priority << '\n';
					break;
				}
			}
			else q.push({ind_first, ind_second});
		}
	}
}

/*
	추후에 알게된 사실인데 priority_queue를 사용하면, sort를 따로 사용할 필요 없이 내림차순으로 정렬하여 queue를 생성할 수 있다.
	배열이 필요 없이 이를 이용해, 데이터가 들어있는 pair queue와 priority_queue를 생성해 비교해주면 된다.
	
*/