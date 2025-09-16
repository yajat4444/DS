#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

//Insertion of array elemnts into linked list:
void insertEnd(int val) {
    Node* n = new Node{val, nullptr};
    if (!head) { head = n; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

// Count occurrences and delete them
int countAndDeleteAll(int key) {
    int count = 0;

    
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Delete nodes after the head
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* del = curr->next;
            curr->next = del->next;
            delete del;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

// Display the list
void displayList() {
    Node* temp = head;
    if (!temp) { cout << "Empty List"; return; }
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
   
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insertEnd(x);

    cout << "Original List: ";
    displayList();

    int key = 1;
    int cnt = countAndDeleteAll(key);

    cout << "Count: " << cnt << "\n";
    cout << "Updated List: ";
    displayList();
    cout << "\n";

    return 0;
}
