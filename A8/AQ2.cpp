#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

Node* cloneTree(Node* root){
    if(!root) return NULL;
    Node* t = new Node(root->data);
    t->left = cloneTree(root->left);
    t->right = cloneTree(root->right);
    return t;
}

Node** generate(int start, int end, int &size){
    if(start > end){
        size = 1;
        Node** arr = new Node*[1];
        arr[0] = NULL;
        return arr;
    }

    Node** result = new Node*[20];
    size = 0;

    for(int i = start; i <= end; i++){
        int leftSize, rightSize;

        Node** leftTrees = generate(start, i-1, leftSize);
        Node** rightTrees = generate(i+1, end, rightSize);

        for(int l = 0; l < leftSize; l++){
            for(int r = 0; r < rightSize; r++){
                Node* root = new Node(i);
                root->left = cloneTree(leftTrees[l]);
                root->right = cloneTree(rightTrees[r]);
                result[size++] = root;
            }
        }
    }
    return result;
}

void printPreorder(Node* root){
    if(!root){
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    int n = 3;
    int size = 0;
    Node** trees = generate(1, n, size);

    for(int i = 0; i < size; i++){
        printPreorder(trees[i]);
        cout << "\n";
    }
    return 0;
}
