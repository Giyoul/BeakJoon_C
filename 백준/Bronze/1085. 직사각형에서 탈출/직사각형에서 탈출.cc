/*
	
*/

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int min = x;
	if((w-x) < min) min = w-x;
	if(y < min) min = y;
	if((h-y) < min) min = h-y;
	
	cout << min;
}
