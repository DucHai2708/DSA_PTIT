#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
    int top;
    public:
        int a[MAX];
        Stack(){
            top = -1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
};

bool Stack::push(int x){
    if(top >= MAX - 1){
        cout << "Stack overflow" << endl;
        return false;
    }
    else{
        a[++top] = x;
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout << "Stack underflow" << endl;
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top < 0){
        cout << "Stack is empty" << endl;
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return top < 0;
}

bool Stack::isFull(){
    return top == MAX;
}

int main(){
    class Stack s;
    s.push(100);
    s.push(150);
    s.push(200);
    cout << s.pop() << " popped from stack" << endl;
    cout << "First element in stack: " << s.peek() << endl;
    cout << "Elements in stack: " << endl;
    while(!s.isEmpty()){
        cout << s.peek() << endl;
        s.pop();
    }
}