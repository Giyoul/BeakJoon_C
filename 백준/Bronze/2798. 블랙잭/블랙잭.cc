#include <iostream>
#include <string>
using namespace std;

class Card{
	int* card = {0};
	int lastCard;
public:
	Card(int x) { card = new int [x]; lastCard = 0; }	// x의 카드 패를 생성
	void setCard(int x);
	int cardSum(int target);
	~Card() { delete [] card; }
};

void Card::setCard(int x){	// x를 카드에 넣는다.
	card[lastCard++] = x;
}

int Card::cardSum(int target){	// 카드들의 합이 target에 가장 가까운 것을 찾는다.
	int ansum = 0;
	for(int i = 0; i < lastCard-2; i++){
		for(int j = i+1; j < lastCard-1; j++){
			for(int k = j+1; k < lastCard; k++){
				int sum = card[i] + card[j] + card[k];
				if(sum > ansum && sum <= target){
					ansum = sum;
				}
			}
		}
	}
	return ansum;
}

class Console : public Card{
public:
	static void run();
};

void Console::run(){
	int n, targetSum;
	cin >> n >> targetSum;
	Card deck(n);
	
	for(int i = 0; i < n; i++){	//	덱에 들어갈 요소를 전부 입력받고 넣는다.
		int secard;
		cin >> secard;
		deck.setCard(secard);
	}
	
	cout << deck.cardSum(targetSum);	// target에 가장 가까운 합을 찾고 출력한다.
}


int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Console::run();
}
