/*
	peicesize를 N으로 설정해놓고, 한번 테스트 할때마다 /3해준다 peicesize가 1이 될때까지.
	case = -1, 0, 1 셋중에 하나가 될 수 있고, 다른 값이 나오면 false 다음 peice로 넘어간다.
	이를 반복.
	
	recursion으로.
*/

#include <iostream>
using namespace std;

void paper(int map[][2187], int quentity[], int peicesize, int startX, int startY){
	int flag = 1;
	int numPaper = map[startY][startX];
	// cout << '[' << startX << ", " << startY << "] : " << numPaper << " peicesize : " << peicesize << '\n';
	for(int i = startY; i < startY + peicesize; i++){
		for(int j = startX; j < startX + peicesize; j++){
			if(numPaper != map[i][j]){
				// cout << "Break!" << '\n';
				flag = 0;
				break;
			}
		}
		if(flag == 0){
			break;
		}
	}
	
	if(flag == 1){
		// cout << "numPaper : " << numPaper << "\npeicesize : " << peicesize << "\nstartX : " << startX << "\nstartY : " << startY << '\n';
		quentity[numPaper+1]++;	// index 0 >> -1, index 1 >> 0, index 2 >> 1
	}
	else{
		for(int i = startY; i < startY + peicesize; i+=(peicesize/3)){
			for(int j = startX; j < startX + peicesize; j+=(peicesize/3)){
				// cout << "numPaper : " << numPaper << "\npeicesize : " << peicesize << "\nstartX : " << startX << "\nstartY : " << startY << "\n\n";
				paper(map, quentity, peicesize/3, j, i);
			}
		}
	}
}


int arr[2187][2187];	// 이를 전역변수가 아닌 지역변수로 선언하면 "스택 메모리가 초과하여" core dumped가 발생할 수 있다. 

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int peicesize, quentity[3] = {0};	// -1과 0과 1로만 이루어진 종의의 개수는 초기값 각각 0개
	
	cin >> peicesize;
	
	for(int i = 0; i < peicesize; i++){
		for(int j = 0; j < peicesize; j++){
			cin >> arr[i][j];
		}
	}
	
	paper(arr, quentity, peicesize, 0, 0);	// 초기는 0, 0부터 시작하므로 startX, startY를 0으로 초기화
	
	for(int i = 0; i < 3; i++){
		cout << quentity[i] << '\n';
	}
}