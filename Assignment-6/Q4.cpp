#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;

    Node(char x) : data(x), prev(nullptr), next(nullptr) {}
};

int main() {
    int n;
    char x;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!head) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    Node* left = head;
    Node* right = tail;
    bool palindrome = true;

    while (left && right && left != right && left->prev != right) {
        if (left->data != right->data) {
            palindrome = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }

    cout << (palindrome ? "True\n" : "False\n");
}
