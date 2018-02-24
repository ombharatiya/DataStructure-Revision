// Stack


#include<iostream>
#define N 10
using namespace std;

class Stack {
	private:
	int top;
	int a[N];
	
	public:
		Stack();
		void push(int x);
		int pop();
		void printStack();
		bool isEmpty();
};

Stack::Stack() {
	top=-1;
	
}

void Stack::push(int x) {
	if(top==N-1) {
		cout<<"\nSTACK OVERFLOW";
	}
	a[++top]=x;
}

int Stack::pop() {
	if(top==-1) {
		cout<<"\nSTACK UNDERFLOW";
		return -1;
	}
	int temp=a[top--];
	return temp;
}

bool Stack::isEmpty() {
	return (top==-1)
}


void Stack::printStack() {
	
	int temp=top;
	if(top==-1) {
		cout<<"\nNO ELEMENT FOUND";
		return;
	}
	cout<<"\nPrint Stack: top to bottom\n";
	while(top>=0)
		cout<<a[top--]<<" ";
	cout<<"\n";
	top=temp;
}




int main() {
	
	Stack s;
	cout<<"push 10\n";	s.push(10);
	cout<<"push 20\n";	s.push(20);
	cout<<"push 30\n";	s.push(30);
	cout<<"push 40\n";	s.push(40);
	cout<<"push 50\n";	s.push(50);
	cout<<"push 60\n";	s.push(60);
	
	s.printStack();
	
	cout<<"pop: "<<s.pop()<<"\n";
	cout<<"pop: "<<s.pop()<<"\n";
	cout<<"pop: "<<s.pop()<<"\n";
	cout<<"pop: "<<s.pop()<<"\n";
	
	s.printStack();
	
	
	
	
	
}