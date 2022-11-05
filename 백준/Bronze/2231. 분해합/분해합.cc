
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num;
	cin >> num;
	
	for(int i = 0; i < num; i++){
		int sum = i + 1;
		int tmpi = i + 1;
		/*
			아래 코드는
			while(i){
				sum += i % 10;
				i /= 10;
			}
			
			로 해도 성립한다.
		*/
		while(tmpi != 0){
			sum += tmpi % 10;
			tmpi /= 10;
		}
		
		if(num == sum){
			cout << i+1;
			return 0;
		}
	}
	cout << 0;
}
