#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v){ data=v; left=right=NULL; }
};

// Convert BST to DLL (inorder)
void bstToDll(Node* root, Node* &head, Node* &prev){
    if(!root) return;

    bstToDll(root->left, head, prev);

    if(!head) head = root; 
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDll(root->right, head, prev);
}

// Merge two sorted DLLs
Node* mergeDll(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;

    if(a->data < b->data){
        a->right = mergeDll(a->right, b);
        if(a->right) a->right->left = a;
        return a;
    } else {
        b->right = mergeDll(a, b->right);
        if(b->right) b->right->left = b;
        return b;
    }
}

void printDll(Node* head){
    while(head){
        cout << head->data;
        if(head->right) cout << " <-> ";
        head = head->right;
    }
}

int main(){
    // BST 1
    Node* t1 = new Node(20);
    t1->left = new Node(10);
    t1->right = new Node(30);
    t1->right->left = new Node(25);
    t1->right->right = new Node(100);

    // BST 2
    Node* t2 = new Node(5);
    t2->right = new Node(70);

    // Convert to DLLs
    Node *head1=NULL, *prev1=NULL;
    bstToDll(t1, head1, prev1);

    Node *head2=NULL, *prev2=NULL;
    bstToDll(t2, head2, prev2);

    // Merge DLLs
    Node* merged = mergeDll(head1, head2);

    // Print final DLL
    printDll(merged);

    return 0;
}
