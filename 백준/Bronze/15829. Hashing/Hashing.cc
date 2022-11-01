#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	long long n;
	cin >> n;
	
	char c;
	long long sum = 0;
	long long M = 1234567891;
	long long R = 31;
	
	for(long long i = 0; i < n; i++){
		cin >> c;
		long long r = 1;
		for(long long j = 0; j < i; j++){
			r *= R;
			if(r >= M) r %= M;
		}
		sum += ((long long)c - 96) * r;
		if(sum >= M) sum %= M;
	}
	cout << sum;
}
