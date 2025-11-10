/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define MAXLEN 5
using namespace std;
class Queue{
    int rear;
    int front;
    int queue[MAXLEN];
    public:
    Queue(){
        front=rear=-1;
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
        }
        else{
        rear=rear+1;
        queue[rear]=item;
        }
    }
    bool isEmpty(){
        if(front==-1 ||front>rear)
        return true;
        else 
        return false;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"underflow!"<<endl;
        }
        else if(front==0 && rear==0){
            int item=queue[front];
            rear=front=-1;
        }
        else{
            int item=queue[front];
            front++;
        }
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
int main()
{
    Queue q;
    q.display();
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    return 0;
}