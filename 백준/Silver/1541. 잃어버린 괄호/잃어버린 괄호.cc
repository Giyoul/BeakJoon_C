/*

	+ -연산자는 직접 써야되고 stoi쓰고 사용.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string formula, num = "";
	int sum = 0, check = 0;
	
	cin >> formula;
	int size = formula.size();
	
	for(int i = 0; i <= size; i++){
		if(formula[i] == '-' || formula[i] == '+' || i == size){
			if(check == 1){
				sum -= stoi(num);
			}
			else{
				sum += stoi(num);
			}
			if(formula[i] == '-') check = 1;	// 위의 if문 뒤에 쓴 이유는 - 이후의 수들을 바꾸는게 먼저가 되야 하기 때문이다.
			num = "";	// 처음에 num을 초기화해주지 않아서 틀렸다.
		}
		else{
			num += formula[i];
		}
	}
	
	cout << sum;
}