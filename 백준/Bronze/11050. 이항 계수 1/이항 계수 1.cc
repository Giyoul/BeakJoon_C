/*
	이항계수는
	k < 0		// 0
	0 < k < n	// n! / (k!(n-k)!)
	k > n		// 0
	이다.
	
	펙토리알은 recursion을 사용해도 되겠지만, 재귀함수는 성능이 너무 구리다.
	그냥 for문으로 하는거로.
*/

#include <iostream>
#include <string>
using namespace std;

int factorial(int x){
	int result = 1;
	for(int i = 0; i < x; i++){
		result *= (i+1);
	}
	return result;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	cout << factorial(n) / (factorial(k) * factorial(n-k));
	
}


/*
	algorithm의 reverse를 사용해도 된다.
*/