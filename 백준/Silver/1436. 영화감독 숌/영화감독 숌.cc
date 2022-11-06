#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int num = 666;
	int count = 0;
	while(1){
		int tmp = num;
		while(tmp >= 100){
			if(tmp % 1000 == 666){
				count++;
				break;
			}
			tmp /= 10;
		}
		if(n == count){
			cout << num;
			break;
		}		
		num++;		
	}
}
