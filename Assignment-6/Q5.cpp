#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool isCircular(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}

int main() {
    int n, x, makeCircular;
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

    cin >> makeCircular;

    if (tail && makeCircular == 1)
        tail->next = head;

    cout << (isCircular(head) ? "True\n" : "False\n");
}
