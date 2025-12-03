#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

int findPos(int in[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(in[i] == val) return i;
    }
    return -1;
}

Node* build(int in[], int post[], int start, int end, int &postIndex){
    if(start > end) return NULL;

    Node* root = new Node(post[postIndex--]);

    if(start == end) return root;

    int pos = findPos(in, start, end, root->data);

    root->right = build(in, post, pos+1, end, postIndex);
    root->left  = build(in, post, start, pos-1, postIndex);

    return root;
}

void printPreorder(Node* root){
    if(!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    int inorder[]   = {4,2,5,1,6,3};
    int postorder[] = {4,5,2,6,3,1};
    int n = 6;

    int postIndex = n - 1;
    Node* root = build(inorder, postorder, 0, n-1, postIndex);

    printPreorder(root);
    return 0;
}
