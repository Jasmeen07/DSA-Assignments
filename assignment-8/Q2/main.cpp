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
    Node* searchIterative(int key){
        Node*temp=root;
        while(temp!=NULL){
            if(temp->key==key)return temp;
            else if(temp->key<key)temp=temp->right;
            else temp=temp->left;
        }
        return NULL;
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
    
    Node* predecessor(Node* x){
        if(x->left!=NULL){ //if left subtree of node exits toh max element of left subtree is predecesor
            return maximum(x->left);
        }
        Node* p =x->parent;
        while(p!=NULL && x==p->left){ //jb tk 'x' p ka right child nhi bn jata upper move karte rho
            x=p;
            p=p->parent;
        }
        return p;
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
    cout<<endl;
    
    Node* s1=tree.searchRecursive(tree.root,18);
    Node* s2=tree.searchIterative(36);
    if(s1!=NULL)
    cout<<"Found: "<<s1->key<<endl;
    else
    cout<<"Not Found"<<endl;
    
    if(s2!=NULL)
    cout<<"Found: "<<s2->key<<endl;
    else
    cout<<"Not Found"<<endl;
    
    cout<<"Minimum element: "<<tree.minimum(tree.root)->key<<endl;
    cout<<"Maximum element: "<<tree.maximum(tree.root)->key<<endl;
    
    cout<<"Successor(18) = "<<tree.Successor(s1)->key<<endl;
    cout<<"Predecessor(18) = "<<tree.predecessor(s1)->key<<endl;
    return 0;
}