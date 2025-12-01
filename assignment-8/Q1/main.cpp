/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
using namespace std;
class Node{
  public:
  int key;
  Node* left;
  Node* right;
  Node* parent;
  Node(int x){
      key=x;
      left=right=parent=NULL;
  }
};
class BST{
    public:
    Node* root;
    BST(){
        root=NULL;
    }
    Node* insert(Node* node,int key){
        if(node==NULL){
            return new Node(key);
        }
        
        if(key<node->key){
            Node* lchild=insert(node->left,key);
            node->left=lchild;
            lchild->parent=node;
        }
        else if(key>node->key){
            Node* rchild=insert(node->right,key);
            node->right=rchild;
            rchild->parent=node;
        }
        return node;
    }
     void insert(int key){
        root=insert(root,key);
    }
    
    void inorder(Node* root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->key<<" ";
            inorder(root->right);
        }
    }
    void preorder(Node* root){
        if(root!=NULL){
            cout<<root->key<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(Node* root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->key<<" ";
        }
    }
};

int main(){
    BST tree;
    
    tree.insert(25);
    tree.insert(10);
    tree.insert(40);
    tree.insert(18);
    tree.insert(34);
    
    tree.inorder(tree.root);
    cout<<endl;
    tree.preorder(tree.root);
    cout<<endl;
    tree.postorder(tree.root);
    return 0;
}