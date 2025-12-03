#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=NULL; }
};

int findPos(int in[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(in[i] == val) return i;
    }
    return -1;
}

Node* build(int pre[], int in[], int start, int end, int &preIndex){
    if(start > end) return NULL;

    Node* root = new Node(pre[preIndex++]);

    if(start == end) return root;

    int pos = findPos(in, start, end, root->data);

    root->left = build(pre, in, start, pos-1, preIndex);
    root->right = build(pre, in, pos+1, end, preIndex);

    return root;
}

void printPostorder(Node* root){
    if(!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main(){
    int preorder[] = {1,2,4,5,3,6};
    int inorder[]  = {4,2,5,1,3,6};
    int n = 6;

    int preIndex = 0;
    Node* root = build(preorder, inorder, 0, n-1, preIndex);

    printPostorder(root);
    return 0;
}
