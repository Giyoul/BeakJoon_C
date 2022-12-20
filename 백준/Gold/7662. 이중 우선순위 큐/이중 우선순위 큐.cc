/*
	처음에는 priority queue로 만들어 보려 했으나, 너무나도 당연하게 시간초과가 발생했다.
	두 번째에는 map을 사용했는데, 한 가지 간과한 것이 key값이 중복되는 경우를 처리해주지 않아서 오류가 발생했다.
	세 번째로 자동 정렬을 포기하고 vector로 문제를 풀었는데, 이 또한 정렬 과정에서 시간초과가 발생헀다.
	그래서 자동 정렬이 되면서, 빠르고, 맨 앞의 수(최솟값)과 맨 뒤의 수(최대값)를 erase할 수 있는 method를 찾아보니까 multiset이라는 놈이 있었다.

	#include <set>으로 사용하고,
	multiset<int> ms;로 선언한다.	// 기본적으로 오름차순 less<int>
		내림차순은 multiset<int, greater<int>> ms; 로 선언한다.

	ms.insert(30);	// 30을 삽입
	ms.erase(20);	// 20을 삭제
	ms.count(50);	// 50의 개수를 찾기
	이 정도이다.
*/

#include <iostream>
#include <set>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k, num;
	char str;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> k;
		multiset<int> muls;
		for(int j = 0; j < k; j++){
			cin >> str >> num;
			if(str == 'I') muls.insert(num);
			else if(str == 'D'){
				if(muls.empty()) continue;
				else if(num == -1){
					muls.erase(muls.begin());
				}
				else if(num == 1){
					auto it = muls.end();
					muls.erase(--it);
				}
			}
		}
		if(muls.empty()) cout << "EMPTY\n";
		else{
			auto it = muls.end();
			it--;
			cout << *it << ' ' << *muls.begin() << '\n';
		}
	}
}