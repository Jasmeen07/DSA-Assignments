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
int searchInorder(int inorder[],int start,int end,int value){
     for(int i=start;i<=end;i++){
        if(inorder[i] == value)
            return i;
     }
    return -1;
}
Node* buildTree(int inorder[],int postorder[],int instart,int inend,int &postindex){
    if(instart>inend)
       return NULL;
    Node* root=new Node(postorder[postindex--]);
    
    if(instart==inend){
        return root;
    }
    int mid=searchInorder(inorder,instart,inend,root->key);
    root->right=buildTree(inorder,postorder,mid+1,inend,postindex);//right subtree first in post+inorder
    root->left=buildTree(inorder,postorder,instart,mid-1,postindex);
    return root;
}
void printInorder(Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->key << " ";
    printInorder(root->right);
}
int main()
{
    int inorder[]  = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int n = 6;
    int postindex = n-1;

    Node* root = buildTree(inorder,postorder, 0, n - 1, postindex);
    cout << "Tree constructed! (Inorder check): ";
    printInorder(root);

    return 0;
}