#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int v): data(v), next(nullptr), prev(nullptr) {}
};

void correctPointer(Node* head) {
    if (!head) return;
    Node* temp = head;
    // If head->next's prev is not head, fix it.
    if (head->next && head->next->prev != head) {
        head->next->prev = head;
        return;
    }
    // If head->prev is not null, fix it.
    if (head->prev) { head->prev = nullptr; return; }
    temp = temp->next;
    while (temp) {
        if (temp->next && temp->next->prev != temp) {
            temp->next->prev = temp;
            return;
        } else if (temp->prev && temp->prev->next != temp) {
            temp->prev->next = temp;
            return;
        }
        temp = temp->next;
    }
}

void printList(Node* head) {
    Node* t = head;
    while (t) {
        cout<<t->data<<" (prev:";
        if (t->prev) cout<<t->prev->data; else cout<<"-1";
        cout<<") -> ";
        t = t->next;
    }
    cout<<"\n";
}

int main() {
    // create list 1 -> 2 -> 3 -> 4 with a deliberate incorrect pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    // make incorrect prev (pointing to 1 instead of 2's real prev)
    head->next->prev = head; // correct for now
    head->next->next = new Node(3);
    head->next->next->prev = head; // INCORRECT: should be head->next
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout<<"Before correction:\n"; printList(head);
    correctPointer(head);
    cout<<"After correction:\n"; printList(head);
    return 0;
}
