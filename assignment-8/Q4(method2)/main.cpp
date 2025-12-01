/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->key);
    inorder(root->right, arr);
}

bool isBST(Node* root) {
    vector<int> arr;
    inorder(root, arr);

    // Check if sorted strictly increasing
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1])
            return false;
    }
    return true;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << (isBST(root) ? "BST" : "Not BST") << endl;
}
