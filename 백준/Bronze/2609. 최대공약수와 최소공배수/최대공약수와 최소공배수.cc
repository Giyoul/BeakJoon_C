#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int Uclid(int a, int b){	// 유클리드 호제법을 사용한 최대공약수 구하기
    while (b > 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	
	int GCD = Uclid(a, b);	// GCD >> 최대공약수
	int LCM = abs(a*b) / GCD;	// LCM >> 최소공배수  // 순환논법을 사용한 최소공배수 구하기
	
	cout << GCD << '\n' << LCM;	
}