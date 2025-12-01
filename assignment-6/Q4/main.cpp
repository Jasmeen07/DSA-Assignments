#include<iostream>
using namespace std;

class DNode{
public:
    char data;
    DNode *prev,*next;
    DNode(char v){ data=v; prev=next=NULL; }
};

class DLL{
public:
    DNode *head;
    DLL(){ head=NULL; }

    void insertEnd(char v){
        DNode *t=new DNode(v);
        if(!head){ head=t; return; }
        DNode *p=head;
        while(p->next) p=p->next;
        p->next=t;
        t->prev=p;
    }

    bool isPalindrome(){
        if(!head||!head->next) return true;

        DNode *left=head;
        DNode *right=head;

        while(right->next) right=right->next;

        while(left!=right && right->next!=left){
            if(left->data!=right->data) return false;
            left=left->next;
            right=right->prev;
        }
        return true;
    }
};

int main(){
    DLL obj;
    int n;
    char x;

    cout<<"Enter number of characters: ";
    cin>>n;

    cout<<"Enter characters: ";
    for(int i=0;i<n;i++){
        cin>>x;
        obj.insertEnd(x);
    }

    if(obj.isPalindrome()) cout<<"Palindrome\n";
    else cout<<"Not Palindrome\n";

    return 0;
}
