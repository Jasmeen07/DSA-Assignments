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
    
    void intervention(){
        Queue q1;
        Queue q2;
        int n=size();
        int half=n/2;
        for(int i=0;i<half;i++){
            q1.enqueue(dequeue()); //removes elemts for front of original queue and put them in q1
        }
        for(int i=0;i<n-half;i++){
            q2.enqueue(dequeue()); //removes elemts for front of original queue and put them in q2
        }
        while(!q1.isEmpty() && !q2.isEmpty()){
            enqueue(q1.dequeue());
            enqueue(q2.dequeue());
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
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.intervention();

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout<<endl;

    return 0;
}