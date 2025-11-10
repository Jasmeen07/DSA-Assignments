/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define MAXLEN 6
using namespace std;
class Queue{
    int rear;
    int front;
    int queue[MAXLEN];
    int count;
    public:
    Queue(){
        front=rear=-1;
        count=0;
    }
    bool isfull(){
        if(rear==MAXLEN-1){
            return true;
        }
        else return false;
    }
    void enqueue(int item){
        if(isfull()){
            cout<<"overflow"<<endl;
        }
        else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=item;
        count++;
        }
        else{
        rear=rear+1;
        queue[rear]=item;
        count++;
        }
    }
    bool isEmpty(){
        if(front==-1 ||front>rear)
        return true;
        else 
        return false;
    }
    int dequeue(){
        int item;
        if(isEmpty()){
            cout<<"underflow!"<<endl;
        }
        else if(front==0 && rear==0){
             item=queue[front];
            rear=front=-1;
            count--;
        }
        else{
             item=queue[front];
            front++;
            count--;
        }
         if(count==0){
          front=0;
          rear=-1;
        }
        return item;
    }
    int size(){
        return count;
    }
    int frontt(){
        return queue[front];
    }
    void display(){
       if(isEmpty()){
            cout<<"underflow!"<<endl;
        }
        else{
            cout<<"queue elements are: ";
            for(int i=front;i<=rear;i++){
                cout<<queue[i]<<" ";
            }
        }
    }
};
class stack{
    Queue q;
    public:
    void push(int x){
        int n=q.size();
        q.enqueue(x);
        
        for(int i=0;i<n;i++){
            q.enqueue(q.frontt()); //shifts element in front to back
            q.dequeue(); //removes ele from front
        }
    }
    void pop(){
        if(q.isEmpty()){
            cout<<"stack underflow!";
        }
        else
        q.dequeue();
    }
    int top(){
        return q.frontt();
    }
};
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    return 0;
}