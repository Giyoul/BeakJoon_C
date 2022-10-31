/*
	deque를 구현하고 사용하는 문제인데, 그냥 갖다 써도 되지만, 진짜 구현해보기로 하겠다.
	
	class Deque에는 아래의 기능을 넣는다.
	push_front X: 정수 X를 덱의 앞에 넣는다.
	push_back X: 정수 X를 덱의 뒤에 넣는다.
	pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 덱에 들어있는 정수의 개수를 출력한다.
	empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
	front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		
	private에는 데이터를 저장할 공간과(동적할당을 위한 포인터 사용) 처음과 끝을 가리키는 index를 선언한다.
*/

#include <iostream>
#include <string>
using namespace std;

class Deque{
	int * deque = {0};
	int head, tail;
public:
	Deque(int n) { deque = new int [n]; head = -1; tail = -1; }
	void push_front(int x);
	void push_back(int x);
	void pop_front();
	void pop_back();
	void size();
	void empty();
	void front();
	void back();
	
	~Deque(){
		delete [] deque;
	}
};

//	push_front X: 정수 X를 덱의 앞에 넣는다.
void Deque::push_front(int x){
	if(tail == -1){	// 들어 있는 수가 없는 경우
		head = 0;
		tail = 0;
		deque[head] = x;
	}
	else{
		for(int i = tail; i >= head; i--){
			deque[i+1] = deque[i];
		}
		deque[head] = x;
		tail++;
	}
}

//	push_back X: 정수 X를 덱의 뒤에 넣는다.
void Deque::push_back(int x){
	if(tail == -1){
		head = 0;
		tail = 0;
		deque[tail] = x;
	}
	else{
		deque[++tail] = x;
	}
}

//	pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Deque::pop_front(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << deque[head] << '\n';
		for(int i = 0; i < tail + 1; i++){
			deque[i] = deque[i+1];
		}
		deque[tail--] = 0;
	}
}

//	pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Deque::pop_back(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << deque[tail] << '\n';
		deque[tail--] = 0;
	}
}

//	size: 덱에 들어있는 정수의 개수를 출력한다.
void Deque::size(){
	if(tail == -1){
		cout << 0 << '\n';
	}
	else{
		int siz = tail - head + 1;
		cout << siz << '\n';
	}
}

//	empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
void Deque::empty(){
	if(tail == -1){
		cout << 1 << '\n';
	}
	else{
		cout << 0 << '\n';
	}
}

//	front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Deque::front(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << deque[head] << '\n';
	}
}

//	back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Deque::back(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << deque[tail] << '\n';
	}
}


class Console : public Deque{	// static 클래스를 사용하여 main에서 클래스 이름으로 run() 실행
public:
	static void run();
};

void Console::run(){
	int n;
	cin >> n;
	Deque deq(n);
	
	string str;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> num;
			deq.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			deq.push_back(num);
		}
		else if (str == "pop_front") {
			deq.pop_front();
		}
		else if (str == "pop_back") {
			deq.pop_back();
		}
		else if (str == "size") {
			deq.size();
		}
		else if (str == "empty") {
			deq.empty();
		}
		else if (str == "front") {
			deq.front();
		}
		else if (str == "back") {
			deq.back();
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Console::run();
}
