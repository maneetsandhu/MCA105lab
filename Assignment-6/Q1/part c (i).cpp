#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

void insertEnd(Node*& head, int x) {
    Node* node = new Node(x);

    if (!head) {
        head = node;
        return;
    }

    Node* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = node;
    node->prev = cur;
}

bool insertBefore(Node*& head, int target, int value) {
    Node* cur = head;
    while (cur && cur->data != target)
        cur = cur->next;

    if (!cur) return false;

    Node* node = new Node(value);
    node->next = cur;
    node->prev = cur->prev;

    if (cur->prev)
        cur->prev->next = node;
    else
        head = node;

    cur->prev = node;
    return true;
}

bool insertAfter(Node* head, int target, int value) {
    Node* cur = head;
    while (cur && cur->data != target)
        cur = cur->next;

    if (!cur) return false;

    Node* node = new Node(value);
    node->prev = cur;
    node->next = cur->next;

    if (cur->next)
        cur->next->prev = node;

    cur->next = node;
    return true;
}

int main() {
    Node* head = nullptr;
    int n, x, target, value;
    char choice;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }

    cin >> choice >> target >> value;

    bool done;
    if (choice == 'B' || choice == 'b')
        done = insertBefore(head, target, value);
    else
        done = insertAfter(head, target, value);

    if (!done) cout << "Target not found\n";

    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}
