/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include <algorithm>
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
    
    Node* searchRecursive(Node* root,int key){
        if(root==NULL || root->key==key){
            return root;
        }
        if(key<root->key){
            return searchRecursive(root->left,key);
        }
        else{
            return searchRecursive(root->right,key);
        }
    }
    
    Node* maximum(Node* x){
        while(x->right!=NULL){
            x=x->right;
        }
        return x;
    }
    
     Node* minimum(Node* x){
        while(x->left!=NULL){
            x=x->left;
        }
        return x;
    }
    
    Node* Successor(Node* x){
        if(x->right!=NULL) // if right subtree of the node  exists
           return minimum(x->right);
        
        Node* p =x->parent;
        while(p!=NULL && x==p->right){ //jb tk x p ka right child hai upper move karte rho
            x=p;
            p=p->parent;
        }
        return p;
    }
    
    Node* deleteNode(Node* root,int key){
        if(root==NULL)return NULL;
        
        if(key>root->key){
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->key){
            root->left=deleteNode(root->left,key);
        }
        else{ //key==root.key
            if(root->left==NULL){
                Node*temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                Node*temp=root->left;
                delete root;
                return temp;
            }
            else{ //when both children exist
                Node*temp=minimum(root->right);//inorder successor
                root->key=temp->key;
                root->right=deleteNode(root->right,temp->key);
            }
        }
        return root;
    }
    void remove(int key){
        root=deleteNode(root,key);
    }
    
    int maxDepth(Node* x){
        if(x==NULL)return 0;
        return 1+max(maxDepth(x->left),maxDepth(x->right));
    }
    
    int minDepth(Node* x){
        if(x==NULL)return 0;
        else if(x->left==NULL)return 1+minDepth(x->right);
        else if(x->right==NULL)return 1+minDepth(x->left);
        else return 1+min(minDepth(x->left),minDepth(x->right));
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
    tree.remove(10);
    tree.inorder(tree.root);
    cout<<endl;
    Node* s1=tree.searchRecursive(tree.root,18);
    cout<<"Max Depth = "<<tree.maxDepth(tree.root)<<endl;
    cout<<"Min Depth = "<<tree.minDepth(tree.root)<<endl;
    return 0;
}