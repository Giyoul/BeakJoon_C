#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num;
	cin >> num;
	for(int i = 0; i < num; i++){
		int k, n;
		cin >> k >> n;
		int arr[k+1][n];
		
		for(int j = 0; j < n; j++){
			arr[0][j] = j+1;
		}
		for(int j = 0; j < k; j++){
			for(int h = 0; h < n; h++){
				if(h == 0){
					arr[j+1][h] = arr[j][h];
				}
				else{
					arr[j+1][h] = arr[j+1][h-1] + arr[j][h];
				}
			}
		}
		cout << arr[k][n-1] << '\n';
		
	}
}
