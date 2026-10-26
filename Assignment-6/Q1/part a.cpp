#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

void insertBeginning(Node*& head, int x) {
    Node* node = new Node(x);
    node->next = head;

    if (head) head->prev = node;
    head = node;
}

void insertEnd(Node*& head, int x) {
    Node* node = new Node(x);

    if (!head) {
        head = node;
        return;
    }

    Node* cur = head;
    while (cur->next) cur = cur->next;

    cur->next = node;
    node->prev = cur;
}

bool insertAfter(Node* head, int target, int x) {
    while (head && head->data != target)
        head = head->next;

    if (!head) return false;

    Node* node = new Node(x);
    node->next = head->next;
    node->prev = head;

    if (head->next) head->next->prev = node;
    head->next = node;
    return true;
}

bool insertBefore(Node*& head, int target, int x) {
    Node* cur = head;

    while (cur && cur->data != target)
        cur = cur->next;

    if (!cur) return false;

    if (cur == head) {
        insertBeginning(head, x);
        return true;
    }

    Node* node = new Node(x);
    node->prev = cur->prev;
    node->next = cur;

    cur->prev->next = node;
    cur->prev = node;
    return true;
}

bool deleteValue(Node*& head, int value) {
    Node* cur = head;

    while (cur && cur->data != value)
        cur = cur->next;

    if (!cur) return false;

    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if (cur->next) cur->next->prev = cur->prev;

    delete cur;
    return true;
}

void search(Node* head, int value) {
    int position = 1;

    while (head) {
        if (head->data == value) {
            cout << "Found at position " << position << '\n';
            return;
        }
        head = head->next;
        position++;
    }

    cout << "Not found\n";
}

void display(Node* head) {
    if (!head) cout << "List is empty\n";

    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, value, target;

    do {
        cout << "\n1.Insert beginning  2.Insert end\n"
             << "3.Insert before     4.Insert after\n"
             << "5.Delete value      6.Search\n"
             << "7.Display           0.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                insertBeginning(head, value);
                break;
            case 2:
                cin >> value;
                insertEnd(head, value);
                break;
            case 3:
                cin >> target >> value;
                if (!insertBefore(head, target, value))
                    cout << "Target not found\n";
                break;
            case 4:
                cin >> target >> value;
                if (!insertAfter(head, target, value))
                    cout << "Target not found\n";
                break;
            case 5:
                cin >> value;
                if (!deleteValue(head, value))
                    cout << "Value not found\n";
                break;
            case 6:
                cin >> value;
                search(head, value);
                break;
            case 7:
                display(head);
                break;
        }
    } while (choice != 0);
}
