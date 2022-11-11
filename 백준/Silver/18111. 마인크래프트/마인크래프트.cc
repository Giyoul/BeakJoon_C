/*
	마크
	블록 설치 >> 1초 걸림
	블록 부수기 >> 2초 걸림
	
	N, M	>> [N][M]	// int 가능;
	B  초기에 가진 블록의 개수 	// B <  6.4 × 107로  int 가능;
	
	걸리는 시간과, 최종 높이를 출력할 것.
	
	
	조건.
	1. 일단 있는 블록 낮은 곳부터 다 채워넣어본다.
	 1.1 높이가 동일한지 체크한다. 아닐경우 다음코드 반복
	{
		2. 가장 높은 줄을 캔다.
		ㄴ 높이가 동일한지 체크.
		3. 가장 낮은 줄을 높이가 최대한 동일해질 때까지 채운다.
		 ㄴ 여기서도 만약 최대높이와 최소 높이의 차이가 1인데, 블록도 M > 빈 블록의 수 이라면 최대높이와 최소높이의 개수를 구한다.
		  ㄴ 최대높이 <= 최소높이 * 2 >> 빈 블록이 더 많으므로 캐는게 더 빠름.
		   ㄴ 캐야할 블록의 수를 
		  ㄴ 최대높이 > 최소높이 * 2 >> 빈 블럭이 더 적으므로 채우는게 더 빠름.
	}
	 1.2 만약 최대높이와 최소 높이의 차이가 1인 동시에 블록도 M > 빈 블록의 수 이라면 최대높이와 최소높이의 개수를 구한다.
	 ㄴ 최대높이 <= 최소높이 * 2 >> 빈 블록이 더 많으므로 캐는게 더 빠름.
	  ㄴ 캐야할 블록의 수를 세고 시간 계산.
	 ㄴ 최대높이 > 최소높이 * 2 >> 빈 블럭이 더 적으므로 채우는게 더 빠름.
	  ㄴ 채울 블록의 수를 세고 시간 계산.
	  
	  
	위에꺼가 첫번째 솔루션인데, 최소높이에 블록 쌓는게 if문이 들어가서 속도가 생각보다 현저히 느렸다.
	차라리 bruteforce algorithm으로 푸는게 나을 듯.
	
	
	N M B
	제거는 2초, 설치는 1초 걸린다.
	for(i < 256){
		for(N){
			for(M){
				
			}
		}
		// 높이가 i가 만들어 지도록 할 때 "설치에 필요한 블록"과 "캐야하는 블록"을 세고 설치 < 캐야+원래 가진 블록수 일 경우 성립하지 않는다.
		// else는 time = 캐는 블록 *2 + 설치블록이고
		 ㄴ if mintime과 비교 후 mintime보다 작으면 mintime = time; ansHeight = i이다.
	}
	cout << mintime << ' ' << ansHeight;
*/

#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N, M, B;
	cin >> N >> M >> B;	// B는 초기에 가진 블록의 수
	
	int arr[N+1][M+1];
	
	for(int i = 0; i < N; i++){	// 데이터 입력받기
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
	
	int mintime = 256 * 2 * N * M + 1;	// 가장 짧은 시간안에 고르기가 가능한 시간의 최대값과,
	int ansHeight;						//  그 때의 높이이다.
	
	for(int i = 0; i <= 256; i++){	// 블록의 최대 높이는 256이므로 256까지 브루트 포스
		int install = 0, dig = 0;	// 설치에 필요한 블록과 캐야하는 블록의 총 합이다.
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				int height = arr[j][k] - i;
				if(height > 0){
					dig += height;
					// cout << "TEST : i = " << i << ", and ["<< j << ", " << k << "]\n";	
				}
				else if(height < 0){
					install -= height;	// height가 음수이므로 이렇게 해야 양수의 값이 들어간다.
					// cout << "install : " << install << '\n';
				}
			}
		}
		if(install <= dig+B){	// 높이가 i가 만들어 지도록 할 때 "설치" < "캐야"+"원래 가진 블록"수 일 경우 성립하지 않는다.
			int time = dig * 2 + install;
			if(time <= mintime){	// 시간 비교
				mintime = time;
				ansHeight = i;
			// cout << "TEST, ansHeightInsert = " << ansHeight << ", and mintime: " << mintime << '\n';
			}
			// cout << "TEST : i = " << i << ", and time: " << time << '\n';
		}
	}
	
	cout << mintime << ' ' << ansHeight;
	
	
}