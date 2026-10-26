#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void insertBeginning(Node*& head, int x) {
    Node* node = new Node(x);
    node->next = head;
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
}

bool insertBefore(Node*& head, int target, int x) {
    if (!head) return false;
    if (head->data == target) {
        insertBeginning(head, x);
        return true;
    }

    Node* cur = head;
    while (cur->next && cur->next->data != target)
        cur = cur->next;

    if (!cur->next) return false;

    Node* node = new Node(x);
    node->next = cur->next;
    cur->next = node;
    return true;
}

bool insertAfter(Node* head, int target, int x) {
    Node* cur = head;
    while (cur && cur->data != target)
        cur = cur->next;

    if (!cur) return false;

    Node* node = new Node(x);
    node->next = cur->next;
    cur->next = node;
    return true;
}

void deleteBeginning(Node*& head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd(Node*& head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* cur = head;
    while (cur->next->next)
        cur = cur->next;

    delete cur->next;
    cur->next = nullptr;
}

bool deleteValue(Node*& head, int value) {
    if (!head) return false;

    if (head->data == value) {
        deleteBeginning(head);
        return true;
    }

    Node* cur = head;
    while (cur->next && cur->next->data != value)
        cur = cur->next;

    if (!cur->next) return false;

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
    return true;
}

void search(Node* head, int value) {
    int position = 1;
    while (head) {
        if (head->data == value) {
            cout << "Position: " << position << '\n';
            return;
        }
        head = head->next;
        position++;
    }
    cout << "Not found\n";
}

void display(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, value, target;

    do {
        cout << "\n1.Insert at beginning\n2.Insert at end\n"
             << "3.Insert before a value\n4.Insert after a value\n"
             << "5.Delete beginning\n6.Delete end\n7.Delete a value\n"
             << "8.Search\n9.Display\n0.Exit\n";
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
                deleteBeginning(head);
                break;
            case 6:
                deleteEnd(head);
                break;
            case 7:
                cin >> value;
                if (!deleteValue(head, value))
                    cout << "Value not found\n";
                break;
            case 8:
                cin >> value;
                search(head, value);
                break;
            case 9:
                display(head);
                break;
        }
    } while (choice != 0);
}
