/*
	쉽게 풀수 있는데, 루트 씌우고 정수로 바꾸고 원래 수에서 빼주고, count++
	위의 빼고 남은 수를 다시 루트 씌우고 정수로 바꾸고 그 수를 원래 수에써 뺴주고, count++
	위의 과정을, 수가 0이 될때까지 반복하면 된다.
	cmath쓰고 square 쓰면 그냥 되는거 아닌가?

	이거랑 브루트 포스로 dp문제로 푸는거랑 뭐가 더 빠른지는 모르겠다.
	확실한건 위의 시퀀스가 코드는 확실히 짧을 듯.
	
	이라고 생각했는데, 위의 과정은 11339의 경우 106^2을 채택해서 굳이 5번으로 나타낸다.
	가장 적은 횟수의 제곱수의 합을 따지지는 못한다는 소리이다.
	
	결국 dp에 브루트포스를 섞어서 푸는 수밖에 없다.
	
	일단 실패했던 코드이다.
	
	#include <iostream>
	#include <cmath>
	using namespace std;

	int main(){
		ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		double num;
		int sqrtNum, count = 0;

		cin >> num;
		while(num != 0){
			sqrtNum = sqrt(num);
			num -= sqrtNum * sqrtNum;
			cout << "sqrtNum = " << sqrtNum << " num = " << num << '\n';
			count++;
		}
		cout << count;
	}
	
	솔직히 말하자면 브루트포스로만 어찌어찌 풀어보려 했는데, 시간이 너무 오래걸렸다. (3중 for문 사용함)
	그래서 뭔가 놓친것 같아서 찾아보니	접근부터가 잘못되었다.
	
	처음부터 끝까지 한번의 시행으로 dp를 만들면 최선의 값을 찾는게 아니게 된다.
	점화식을 도저히 만들수가 없어서 찾아보니,
	dp[50]을 구할 때
	dp[1]+dp[49]
	dp[4]+dp[46]
	dp[9]+dp[41]
	dp[16]+dp[34]
	dp[25]+dp[25]
	dp[36]+dp[14]
	이므로 점화식이 dp[n] = dp[i*i] + dp[n-i*i]가 된다.
	이를 이용해서
	
	일단 i^2의 값들은 1번의 시도로 가능하니 dp[i*i]에 1을 넣어주고,
	n에 도달할 때 까지 dp를 갱신해주면 된다.
	
	알고보니 쉬운문제.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	int dp[50001] = {0};	// 모든 횟수를 0으로 초기화
	
	cin >> n;
	
	for(int i = 1; i*i <= n; i++){
		dp[i*i] = 1;	// i^2의 값들은 1번의 시도로 가능하니 dp[i*i]에 1을 넣어준다.
	}
	
	for(int i = 1; i <= n; i++){	// dp의 최솟값 갱신
		if(dp[i] != 0) continue;	// i가 어떤 수의 제곱수일 경우. 1이니 이것보다 더 적은 횟수의 연산이 불가하기 때문에 건너뛰기
		else{
			for(int j = 1; j*j <= i; j++){
				if(dp[i] == 0) dp[i] = dp[j*j] + dp[i - j*j];	// 이게 성립하는 이유는, j가 무조건 i보다 작을 수 밖에 없기 때문에 그 수들은 무조건 0이 아니기 떄문이다.
				else{
					dp[i] = min(dp[i], dp[j*j] + dp[i - j*j]);	// dp에서 만들어진 값 중에 더 작은값으로 저장 (갱신)
				}
			}
		}
	}
	cout << dp[n];	
}

/*
	역시 점화식이 문제였던 문제
*/