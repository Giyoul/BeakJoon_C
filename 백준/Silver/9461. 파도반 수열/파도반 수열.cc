/*
	딱 보니 dp인데 점화식이 어찌되려나
	
	처음 10개는 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 이고,
	index 5 = index 0 + index 4
	6 = 2 + 5
	7 = 3 + 6
	8 = 4 + 7
	9 = 5 + 8 이런식이다.
	
	그러면 n >= 6인 동안, arr[n] = arr[n-4] + arr[n-1]이다.
	이거로 구해보면 될듯
	일단 index 5까지는 1, 1, 1, 2, 2, 3 집어넣고 시작하자.
	
	인 줄 알았는데 큰 수로 가니까 뭔가 이상하다.
	arr[n] = arr[n-3] + arr[n-2]를 해도 똑같다.
	
	그래서 점화식 부분을 둘 다 코드를 짜서 해봤는데, 전자는 틀리고 후자는 맞다고 한다.
*/

#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	long long arr[100] = {1, 1, 1, 2, 2, 3};
	int testcase, n;
	
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		cin >> n;
		for(int j = 6; j < n; j++){
			arr[j] = arr[j-5] + arr[j-1];	// 점화식
		}
		cout << arr[n-1] << '\n';
	}
}
