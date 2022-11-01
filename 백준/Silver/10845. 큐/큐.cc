/*
	큐를 구현하는 코드
	
	push X: 정수 X를 큐에 넣는 연산이다.
	pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 큐에 들어있는 정수의 개수를 출력한다.
	empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
	front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	
*/

#include <iostream>
#include <string>
using namespace std;

class Queue{
	int * queue = {0};
	int head, tail;
public:
	Queue(int n) { queue = new int [n]; head = -1; tail = -1; }
	void push(int x);
	void pop();
	void size();
	void empty();
	void front();
	void back();
	~Queue() { delete [] queue; }
};

//	push X: 정수 X를 큐에 넣는 연산이다.
void Queue::push(int x){
	if(tail == -1){	// queue가 비어있는 경우
		head = 0;
		tail = 0;
		queue[head] = x;
	}
	else{
		queue[++tail] = x;
	}
}

//	pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Queue::pop(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << queue[head] << '\n';
		for(int i = 0; i < tail; i++){
			queue[i] = queue[i+1];
		}
		queue[tail] = 0;
		tail--;
	}
} 

//	size: 큐에 들어있는 정수의 개수를 출력한다.
void Queue::size(){
	if(tail == -1){
		cout << 0 << '\n';
	}
	else{
		cout << tail - head + 1 << '\n';
	}
}

// 	empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
void Queue::empty(){
	if(tail == -1){
		cout << 1 << '\n';
	}
	else{
		cout << 0 << '\n';
	}
}

// 	front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Queue::front(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << queue[head] << '\n';
	}
}

// 	back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void Queue::back(){
	if(tail == -1){
		cout << -1 << '\n';
	}
	else{
		cout << queue[tail] << '\n';
	}
}


class Console : public Queue{
public:
	static void run();
};

void Console::run(){
	int n;
	cin >> n;
	Queue q(n);
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		if(str == "push"){
			int num;
			cin >> num;
			q.push(num);
		}
		else if(str == "pop"){
			q.pop();
		}
		else if(str == "size"){
			q.size();
		}
		else if(str == "empty"){
			q.empty();
		}
		else if(str == "front"){
			q.front();
		}
		else if(str == "back"){
			q.back();
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	Console::run();
}
