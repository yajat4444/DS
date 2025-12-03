#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

bool isLeaf(Node* x){
    return x && !x->left && !x->right;
}

int sumLeftLeaves(Node* root){
    if(!root) return 0;
    int sum = 0;
    if(isLeaf(root->left)) sum += root->left->data;
    else sum += sumLeftLeaves(root->left);
    sum += sumLeftLeaves(root->right);
    return sum;
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << sumLeftLeaves(root);
    return 0;
}
