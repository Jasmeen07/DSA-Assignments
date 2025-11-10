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
  
  void findMiddle(){
      Node* fast= head;
      Node* slow=head;
      if(head!=NULL){
      while(fast!=NULL && fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
      }
      cout<<"Middle element is : "<<slow->data;
  }
  }
  int delete_key(int key){
      Node*temp=head;
      Node*prev=NULL;
          int count=0;
         
          while(head!=NULL && head->data==key){ //key at beginning
              temp=head;
              head=head->next;
              delete temp;
              count++;
          }
          Node*current=head;
          while(current!=NULL){
              if(current->data==key){
                 temp=current;
                 prev->next=current->next;
                 current=current->next;
                 delete temp;
                 count++;
              }
              else{
                   prev=current;
                   current=current->next;
              }
          }
          return count;
      }
};
int main()
{
    LinkedList l;
	l.insert_beg(1);
	l.insert_end(3);
	l.insert_end(2);
	l.insert_end(3);
	l.insert_beg(4);
	l.insert_val(5,2);
	l.print();
	l.search(3);
	l.search(5);
	l.findMiddle();
	cout<<"\nTotal no of 3 in list:"<<l.delete_key(3)<<endl;
	l.print();
    return 0;
}