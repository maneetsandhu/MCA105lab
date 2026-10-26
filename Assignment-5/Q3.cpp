#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

int main() {
    int n, x;
    Node* head = nullptr;
    Node* tail = nullptr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    if (!head) {
        cout << "List is empty\n";
        return 0;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle: " << slow->data << '\n';
}
