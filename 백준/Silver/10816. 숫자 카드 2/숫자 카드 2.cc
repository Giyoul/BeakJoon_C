#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	int card[n] = {0};
	
	for(int i = 0; i < n; i++){
		cin >> card[i];
	}
	sort(card, card+n);
	
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int num;
		cin >> num;
		cout << upper_bound(card, card+n, num) - lower_bound(card, card+n, num) << ' ';
	}
	
}
