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
Node* buildTree(int inorder[],int preorder[],int instart,int inend,int &preindex){
    if(instart>inend)
       return NULL;
    Node* root=new Node(preorder[preindex++]);
    
    if(instart==inend){
        return root;
    }
    int mid=searchInorder(inorder,instart,inend,root->key);
    root->left=buildTree(inorder,preorder,instart,mid-1,preindex);
    root->right=buildTree(inorder,preorder,mid+1,inend,preindex);
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
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int n = 6;
    int preIndex = 0;

    Node* root = buildTree(inorder, preorder, 0, n - 1, preIndex);
    cout << "Tree constructed! (Inorder check): ";
    printInorder(root);

    return 0;
}