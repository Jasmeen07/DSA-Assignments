/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
  Node(){
      data=0;
      next=NULL;
  }
  Node(int data){
      this->data=data;
      this->next=NULL;
  }
};
class LinkedList{
  Node *head;
  public:
  LinkedList(){
      head=NULL;
  }
  void insert_beg(int data){
      Node *newnode=new Node(data);
      newnode->data=data;
      newnode->next=head;
      head=newnode;
  }
  void insert_end(int data){
      Node *newnode=new Node(data);
      if(head==NULL){
          head=newnode;
          return;
      }
      else{
          Node*temp=head;
          while(temp->next!=NULL){
              temp=temp->next;
          }
          temp->next=newnode;
      }
  }
  void print(){
       Node*temp=head;
       if(temp==NULL){
           cout<<"list is empty!"<<endl;
       }
       else{
           while(temp!=NULL){
               cout<<temp->data<<" ";
               temp=temp->next;
           }
           cout<<endl;
       }
      
  }
  void insert_val(int num,int val){
      Node*newnode=new Node();
      newnode->data=num;
      newnode->next=NULL;
      if(head==NULL){
          head=newnode;
          return;
      }
      else{
          Node*temp=head;
          while(temp->next!=NULL && temp->data!=val){
              temp=temp->next;
          }
          if(temp==NULL){
              cout<<"No such node exists!"<<endl;
          }
          else{
              newnode->next=temp->next;
              temp->next=newnode;
          }
      }
  }
  void search(int x){
      Node*temp=head;
      if(head==NULL){
          cout<<"list is empty!"<<endl;
      }
      else{
          while(temp!=NULL){
              if(temp->data==x){
                  cout<<"element found!"<<endl;
                  return;
              }
              temp=temp->next;
          }
          cout<<"element not found";
      }
  }
  
  
  
};
int main()
{
    LinkedList l;
	l.insert_beg(1);
	l.insert_end(2);
	l.insert_end(3);
	l.insert_beg(4);
	l.insert_val(5,2);
	l.print();
	l.search(3);
	l.search(5);
    return 0;
}