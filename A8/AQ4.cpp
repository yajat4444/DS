#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

void rightViewUtil(Node* root, int level, int &maxLevel){
    if(!root) return;
    if(level > maxLevel){
        cout << root->data << " ";
        maxLevel = level;
    }
    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

void rightView(Node* root){
    int maxLevel = 0;
    rightViewUtil(root, 1, maxLevel);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    rightView(root);
    return 0;
}
