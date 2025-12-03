#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

int maxDepth(Node* root){
    if(!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << maxDepth(root);
    return 0;
}
