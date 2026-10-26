#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x) : data(x), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int x) : data(x), next(nullptr) {}
};

int main() {
    int n, x;
    cin >> n;

    DNode* dHead = nullptr;
    DNode* dTail = nullptr;
    CNode* cHead = nullptr;
    CNode* cTail = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;

        DNode* d = new DNode(x);
        if (!dHead) dHead = dTail = d;
        else {
            dTail->next = d;
            d->prev = dTail;
            dTail = d;
        }

        CNode* c = new CNode(x);
        if (!cHead) cHead = cTail = c;
        else {
            cTail->next = c;
            cTail = c;
        }
    }

    if (cTail) cTail->next = cHead;

    int dllSize = 0;
    for (DNode* cur = dHead; cur; cur = cur->next)
        dllSize++;

    int cllSize = 0;
    if (cHead) {
        CNode* cur = cHead;
        do {
            cllSize++;
            cur = cur->next;
        } while (cur != cHead);
    }

    cout << "Doubly list size: " << dllSize << '\n';
    cout << "Circular list size: " << cllSize << '\n';
}
