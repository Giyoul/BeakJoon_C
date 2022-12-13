/*
	문자열 길이만큼  for문 사용,
	I는 다음에 O 나오면 count++ O는 I가 다음으로 나오면 count++해주기
	count가 0일 떄 시작이 I이면 count 시작하고, count가 3보다 작으면 문자열에 저장하지 않음.
	count가 3보다 크면 배열에 그 사이즈를 저장하고,
	도중에 입력받은 M(IOI의 길이)을 가지고 몇 군대 포함되어있는지 계산해야 하는데,
	위의 사이즈 저장 배열에 저장한 수 - N / 2 + 1 해준다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M;	// N은 IOI의 P(N), M은 문자열의 길이
	int ans = 0, count = 0;
	string str;
	vector<int> v;

	cin >> N >> M >> str;
	for(int i = 0; i < M; i++){
		if(count == 0){
			if(str[i] == 'I'){
				count++;
			}
		}
		else{
			if(str[i-1] == 'I' && str[i] == 'O'){
				count++;
			}
			else if(str[i-1] == 'O' && str[i] == 'I'){
				count++;
			}
			else{
				if(count >= 3){
					if(count % 2 == 0){
						v.push_back(count/2 - 1);
					}
					else{
						v.push_back(count/2);
					}
				}
				count = 0;
				i--;
			}
		}
		if(i+1 == M){
			if(count >= 3){
				if(count % 2 == 0){
					v.push_back(count/2 - 1);
				}
				else{
					v.push_back(count/2);
				}
			}
		}
	}

	for(int i = 0; i < v.size(); i++){
		if(v[i] < N) continue;
		ans += (v[i] - N + 1);
	}
	cout << ans;	
}