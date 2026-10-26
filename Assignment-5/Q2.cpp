#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

int main() {
    int n, x, key, count = 0;
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
    cin >> key;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == key) {
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            count++;
        } else {
            cur = cur->next;
        }
    }

    cout << "Count: " << count << "\nUpdated List: ";
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}
