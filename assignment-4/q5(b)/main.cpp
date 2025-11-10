/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

***************************************************************************/
#include <iostream>
#define MAXLEN 100
using namespace std;

class Queue {
    int arr[MAXLEN];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == MAXLEN - 1; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};
class Stack{
    public:
    Queue q1,q2;
    void push(int x){
        q2.enqueue(x);
        
        while(!q1.isEmpty()){
            q2.enqueue(q1.dequeue());
        }
        Queue temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        if(q1.isEmpty()){
            cout<<"underflow";
        }
        else
            q1.dequeue();
    }
     int top() {
        if (q1.isEmpty()) return -1;
        return q1.getFront();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // 30
    s.pop();
    cout << "Top: " << s.top() << endl; // 20
    s.push(40);
    cout << "Top: " << s.top() << endl; // 40

    
    return 0;
}