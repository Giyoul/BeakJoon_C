/*
	그냥 recursion 하기
*/

#include <iostream>
#include <cmath>
using namespace std;

void check(int x, int y, int targety, int targetx, int &count, int size){
	if(y == targety && x == targetx){
		cout << count;
		return;
	}
	else if(targetx < x + size && targety < y + size && targetx >= x && targety >= y){
        check(x, y, targety, targetx, count, size / 2);
        check(x + size / 2, y, targety, targetx, count, size / 2);
        check(x, y + size / 2, targety, targetx, count, size / 2);
        check(x + size / 2, y + size / 2, targety, targetx, count, size / 2);
    }
	else{	// 한 덩어리의 블록의 사이즈는 넓이와 같다.
        count += size * size;
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, r, c, count = 0;
	cin >> n >> r >> c;

	check(0, 0, r, c, count, pow(2, n));
}