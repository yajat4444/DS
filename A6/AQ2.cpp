#include <iostream>
using namespace std;

struct DNode { int data; DNode* prev; DNode* next; DNode(int v):data(v),prev(nullptr),next(nullptr){} };
struct CNode { int data; CNode* next; CNode(int v):data(v),next(nullptr){} };

inline bool evenParity(int x) { return (__builtin_popcount((unsigned)x) % 2) == 0; }

// DLL remove
DNode* removeEvenParityDLL(DNode* head) {
    DNode* cur = head;
    while (cur) {
        DNode* nxt = cur->next;
        if (evenParity(cur->data)) {
            if (cur->prev) cur->prev->next = cur->next;
            else head = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            delete cur;
        }
        cur = nxt;
    }
    return head;
}

// CLL remove
CNode* removeEvenParityCLL(CNode* head) {
    if (!head) return nullptr;
    // remove nodes from head until head has odd-parity or list empty
    CNode* tail = head;
    while (tail->next != head) tail = tail->next;
    // handle single or many nodes
    int loopGuard = 0;
    while (head && evenParity(head->data) && loopGuard < 1000000) {
        if (head == tail) { delete head; return nullptr; }
        CNode* tmp = head;
        head = head->next;
        tail->next = head;
        delete tmp;
        loopGuard++;
    }
    if (!head) return nullptr;
    CNode* cur = head->next;
    CNode* prev = head;
    while (cur != head) {
        if (evenParity(cur->data)) {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else { prev = cur; cur = cur->next; }
    }
    return head;
}

int main() {
    // Example DLL: 18 <-> 15 <-> 8 <-> 9 <-> 14
    DNode* dh = new DNode(18);
    dh->next = new DNode(15); dh->next->prev = dh;
    dh->next->next = new DNode(8); dh->next->next->prev = dh->next;
    dh->next->next->next = new DNode(9); dh->next->next->next->prev = dh->next->next;
    dh->next->next->next->next = new DNode(14); dh->next->next->next->next->prev = dh->next->next->next;

    dh = removeEvenParityDLL(dh);
    cout<<"DLL after removing even-parity nodes: ";
    for (DNode* t = dh; t; t=t->next) cout<<t->data<<" ";
    cout<<"\n";

    // Example CLL: 9 -> 11 -> 34 -> 6 -> 13 -> 21
    CNode* ch = new CNode(9);
    ch->next = new CNode(11); ch->next->next = new CNode(34);
    ch->next->next->next = new CNode(6); ch->next->next->next->next = new CNode(13);
    ch->next->next->next->next->next = new CNode(21); ch->next->next->next->next->next->next = ch;

    ch = removeEvenParityCLL(ch);
    cout<<"CLL after removing even-parity nodes: ";
    if (!ch) cout<<"Empty\n";
    else { CNode* t = ch; do { cout<<t->data<<" "; t = t->next; } while (t != ch); cout<<"\n"; }
    return 0;
}
