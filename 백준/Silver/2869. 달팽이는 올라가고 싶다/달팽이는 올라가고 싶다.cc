/*
	2 1 5 >> 4 ((5-2)/(2-1) + 1 == 4) 딱 떨어짐 -
	5 1 6 >> 2 ((6-5)/(5-1) + 1 == 2) 0.25 반올림
	6 1 5 >> 1 
	4 2 9 >> 4 ((9-4)/(4-2) + 1 == 3) 0.5 반내림
	
	위 알고리즘을 역산해 보았을 때, 공식이 나오므로 브루트포스 알고리즘을 사용할 필요가 없다.
	A B V순으로 값을 받을 때
	(V-A)/(A-B) + 1을 하면 된다.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int A, B, V;
	cin >> A >> B >> V;
	int ans = (V-A)/(A-B) + 1;
	if((V-A)%(A-B) != 0){
        ans++;
	}
	if(V < A) cout << 1;
	else{
		cout << ans;
	}
}