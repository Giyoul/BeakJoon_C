#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void binary_search(int num, int arr[], int size){	// 찾으면 1 없으면 0 출력
	int first = 0;
	int last = size - 1;
	int flag = 0;	// 0 >> 못찾음	, 1 >> 찾음
	while(first <= last){
		int mid = (last + first) / 2;
		if(arr[mid] == num){
			flag = 1;
			break;
		}
		else if(arr[mid] < num){
			first = mid + 1;
		}
		else{
			last = mid - 1;
		}
	}
	cout << flag << '\n';
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	int* srcarr = new int [n];
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		srcarr[i] = num;
	}
	sort(srcarr, srcarr + n);
	
	int size = n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		binary_search(num, srcarr, size);
	}
	delete [] srcarr;
}
