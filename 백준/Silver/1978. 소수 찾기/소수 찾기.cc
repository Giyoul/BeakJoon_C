/*
	에라토스테네스의 체를 사용하는 알고리즘 문제이다.
	
	아래는 에라도스테네스의 체의 구조이다.
	
	int number = 100000;
	int a[1000001];

	void primeNumberSieve() {

		// 1. 배열을 생성하여 초기화한다.
		for(int i=2;i<=number;i++) {
			a[i] = i;
		}

		// 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
		// (지울 때 자기자신은 지우지 않고, 이미 지워진 수는 건너뛴다.)
		for(int i=2;i<=number;i++) {
			if(a[i]==0) continue; // 이미 지워진 수라면 건너뛰기

			// 이미 지워진 숫자가 아니라면, 그 배수부터 출발하여, 가능한 모든 숫자 지우기
			for(int j=2*i;j<=number; j+=i) {
				a[j] = 0;
			}
		}

		// 3. 2부터 시작하여 남아있는 수를 모두 출력한다.
		for(int i=2;i<=number;i++) {
			if(a[i]!=0) printf("%d ", a[i]);
		}
	}
*/

#include <iostream>
#include <string>
using namespace std;

void eratos(int n){
	int era[1001] = {0};
	
	// 배열 초기화
	for(int i = 2; i < 1000; i++){
		era[i] = i;
	}
	
	for(int i = 2; i <= 1000; i++){	// 소수 찾아내기
		if(era[i] == 0) continue;	// 2의 배수인 4같은 경우가 이에 해당한다.
		
		for(int j = 2*i; j <= 1000; j+=i){
			era[j] = 0;
		}
	}
	
	int count = 0;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(era[num] != 0) count++;
	}
	
	cout << count;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	eratos(n);
}
