#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

void splitCLL(Node* head, Node** h1, Node** h2) {
    *h1 = *h2 = nullptr;
    if (!head) return;
    Node* slow = head; Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // for even nodes, move fast one more
    if (fast->next->next == head) fast = fast->next;
    *h1 = head;
    *h2 = slow->next;
    fast->next = *h2;
    slow->next = *h1;
}

void printCLL(Node* head) {
    if (!head) { cout<<"Empty\n"; return; }
    Node* t = head;
    do { cout<<t->data<<" "; t = t->next; } while (t != head);
    cout<<"\n";
}

int main() {
    // example: 10->4->9 (circular)
    Node* head = new Node(10);
    head->next = new Node(4); head->next->next = new Node(9); head->next->next->next = head;
    Node *h1=nullptr,*h2=nullptr;
    splitCLL(head, &h1, &h2);
    cout<<"List 1: "; printCLL(h1);
    cout<<"List 2: "; printCLL(h2);
    return 0;
}
