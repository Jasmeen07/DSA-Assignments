/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#define MAXLEN 6
using namespace std;
class Queue{
    int rear;
    int front;
    char queue[MAXLEN];
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
    void enqueue(char item){
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
        char item;
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
    char frontt(){
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
   void findFirstNonRepeating(){
        Queue q;
        string str;
        cout<<"enter string: ";
        getline(cin,str);
        int count[26]={0}; //make array to count no of times an alphabet is repeated,initialize count of each alphabet by 0
        for(char ch: str){
            if(ch==' ')continue;
            if(ch<'a' || ch>'z')continue;
            int idx=ch-'a';
            count[idx]++;
            q.enqueue(ch);
            
            while(!q.isEmpty() && count[q.frontt()-'a']>1){
                q.dequeue();
            }
            if(q.isEmpty()){
                cout<<"-1 ";
            }
            else
            cout<<q.frontt()<<" ";
            
        }
   }

int main() {
    findFirstNonRepeating();
    return 0;
}