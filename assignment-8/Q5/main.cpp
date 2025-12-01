/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<stack>
using namespace std;
class Node{
  public:
  int key;
  Node* left;
  Node*right;
  Node*parent;
  Node(int k){
      key=k;
  }
};
void inorderNonRecursive(Node* root){
    stack<Node*> st;
    Node* temp=root;
    while(temp!=NULL || !st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        temp=st.top();
        st.pop();
        cout<<temp->key<<" ";
        temp=temp->right;
    }
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    inorderNonRecursive(root);

    return 0;
}