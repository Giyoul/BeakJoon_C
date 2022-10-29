#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int ho = 1;
	int floor, room, num;
	
	for(int i = 0; i < n; i++){
		cin >> floor >> room >> num;
		while(num > 0){
			num -= floor;
			ho++;
		}
		num += floor;
		ho--;
		
		if(ho >= 10) cout << num << ho << '\n';
		else cout << num << '0' << ho << '\n';
		ho = 1;
	}

}