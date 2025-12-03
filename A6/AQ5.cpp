#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right, *up, *down;
    Node(int v): val(v), left(nullptr), right(nullptr), up(nullptr), down(nullptr) {}
};

int main() {
    int r, c;
    cout<<"Enter rows and cols: "; cin>>r>>c;
    vector<vector<int>> mat(r, vector<int>(c));
    cout<<"Enter matrix values:\n";
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) cin>>mat[i][j];

    // create nodes
    vector<vector<Node*>> nodes(r, vector<Node*>(c, nullptr));
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) nodes[i][j] = new Node(mat[i][j]);

    // link neighbors
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if (j+1 < c) nodes[i][j]->right = nodes[i][j+1];
            if (j-1 >=0) nodes[i][j]->left = nodes[i][j-1];
            if (i+1 < r) nodes[i][j]->down = nodes[i+1][j];
            if (i-1 >=0) nodes[i][j]->up = nodes[i-1][j];
        }
    }

    // print matrix via right/down pointers to verify
    cout<<"Traverse row-wise using right:\n";
    for (int i=0;i<r;i++){
        Node* t = nodes[i][0];
        while (t) { cout<<t->val<<" "; t = t->right; }
        cout<<"\n";
    }

    cout<<"Traverse column-wise using down from top-left:\n";
    Node* col = nodes[0][0];
    while (col) {
        Node* t = col;
        while (t) { cout<<t->val<<" "; t = t->down; }
        cout<<"\n";
        col = col->right;
    }
    return 0;
}
