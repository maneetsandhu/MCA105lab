#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

int main() {
    int n, x;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    if (!head) return 0;

    tail->next = head;

    Node* cur = head;
    do {
        cout << cur->data << ' ';
        cur = cur->next;
    } while (cur != head);

    cout << head->data << '\n';
}
