#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

void insertEnd(Node*& tail, int x) {
    Node* node = new Node(x);

    if (!tail) {
        tail = node;
        node->next = node;
        return;
    }

    node->next = tail->next;
    tail->next = node;
    tail = node;
}

bool insertBefore(Node*& tail, int target, int value) {
    if (!tail) return false;

    Node* head = tail->next;

    if (head->data == target) {
        Node* node = new Node(value);
        node->next = head;
        tail->next = node;
        return true;
    }

    Node* cur = head;
    while (cur->next != head && cur->next->data != target)
        cur = cur->next;

    if (cur->next == head) return false;

    Node* node = new Node(value);
    node->next = cur->next;
    cur->next = node;
    return true;
}

bool insertAfter(Node*& tail, int target, int value) {
    if (!tail) return false;

    Node* head = tail->next;
    Node* cur = head;

    do {
        if (cur->data == target) {
            Node* node = new Node(value);
            node->next = cur->next;
            cur->next = node;

            if (cur == tail)
                tail = node;

            return true;
        }
        cur = cur->next;
    } while (cur != head);

    return false;
}

int main() {
    Node* tail = nullptr;
    int n, x, target, value;
    char choice;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(tail, x);
    }

    cin >> choice >> target >> value;

    bool done;
    if (choice == 'B' || choice == 'b')
        done = insertBefore(tail, target, value);
    else
        done = insertAfter(tail, target, value);

    if (!done) cout << "Target not found\n";

    if (tail) {
        Node* head = tail->next;
        Node* cur = head;

        do {
            cout << cur->data << " -> ";
            cur = cur->next;
        } while (cur != head);

        cout << "(back to head)\n";
    }
}
