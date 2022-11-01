/*
	stack을 구현하고 사용하는 문제다.
	
	push X: 정수 X를 스택에 넣는 연산이다.
	pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 스택에 들어있는 정수의 개수를 출력한다.
	empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
	top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	
	private에는 데이터를 저장할 공간과(동적할당을 위한 포인터 사용) 처음과 끝을 가리키는 index를 선언한다.
	
	// 이전에 풀었던 deque 문제와 비슷한 구조로 진행하겠다.
*/

#include <iostream>
#include <string>
using namespace std;

class Stack{
	int * stack = {0};
	int head, tail;
public:
	Stack(int n) { stack = new int [n]; head = -1; tail = -1; }
	void push(int x);
	void pop();
	void size();
	void empty();
	void top();
	
	~Stack(){
		delete [] stack;
	}
};

//	push X: 정수 X를 스택에 넣는 연산이다.
void Stack::push(int x){
	if(tail == -1){	// 들어 있는 수가 없는 경우
		head = 0;
		tail = 0;
		stack[tail] = x;
	}
	else{
		stack[++tail] = x;
	}
}

//	pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Stack::pop(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << stack[tail] << '\n';
		stack[tail--] = 0;
	}
}

//	size: 스택에 들어있는 정수의 개수를 출력한다.
void Stack::size(){
	if(tail == -1){
		cout << 0 << '\n';
	}
	else{
		int siz = tail - head + 1;
		cout << siz << '\n';
	}
}

//	empty: 스택이 비어있으면 1을, 아니면 0을 출력한다.
void Stack::empty(){
	if(tail == -1){
		cout << 1 << '\n';
	}
	else{
		cout << 0 << '\n';
	}
}

//	top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Stack::top(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << stack[tail] << '\n';
	}
}


class Console : public Stack{	// static 클래스를 사용
public:
	static void run();
};

void Console::run(){
	int n;
	cin >> n;
	Stack s(n);
	
	string str;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			s.pop();
		}
		else if (str == "size") {
			s.size();
		}
		else if (str == "empty") {
			s.empty();
		}
		else if (str == "top") {
			s.top();
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	Console::run();
}
