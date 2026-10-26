#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

void insertBeginning(Node*& tail, int x) {
    Node* node = new Node(x);

    if (!tail) {
        tail = node;
        node->next = node;
    } else {
        node->next = tail->next;
        tail->next = node;
    }
}

void insertEnd(Node*& tail, int x) {
    insertBeginning(tail, x);
    tail = tail->next;
}

bool insertAfter(Node* tail, int target, int x) {
    if (!tail) return false;

    Node* head = tail->next;
    Node* cur = head;

    do {
        if (cur->data == target) {
            Node* node = new Node(x);
            node->next = cur->next;
            cur->next = node;

            if (cur == tail) tail = node;
            return true;
        }
        cur = cur->next;
    } while (cur != head);

    return false;
}

bool insertBefore(Node*& tail, int target, int x) {
    if (!tail) return false;

    Node* head = tail->next;

    if (head->data == target) {
        insertBeginning(tail, x);
        return true;
    }

    Node* cur = head;
    while (cur->next != head && cur->next->data != target)
        cur = cur->next;

    if (cur->next == head) return false;

    Node* node = new Node(x);
    node->next = cur->next;
    cur->next = node;
    return true;
}

bool deleteValue(Node*& tail, int value) {
    if (!tail) return false;

    Node* head = tail->next;
    Node* cur = head;
    Node* previous = tail;

    do {
        if (cur->data == value) {
            if (cur == tail && cur == head) {
                tail = nullptr;
            } else {
                previous->next = cur->next;
                if (cur == tail) tail = previous;
            }

            delete cur;
            return true;
        }

        previous = cur;
        cur = cur->next;
    } while (cur != head);

    return false;
}

void search(Node* tail, int value) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* head = tail->next;
    Node* cur = head;
    int position = 1;

    do {
        if (cur->data == value) {
            cout << "Found at position " << position << '\n';
            return;
        }
        cur = cur->next;
        position++;
    } while (cur != head);

    cout << "Not found\n";
}

void display(Node* tail) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* head = tail->next;
    Node* cur = head;

    do {
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);

    cout << "(back to head: " << head->data << ")\n";
}

int main() {
    Node* tail = nullptr;
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
                insertBeginning(tail, value);
                break;
            case 2:
                cin >> value;
                insertEnd(tail, value);
                break;
            case 3:
                cin >> target >> value;
                if (!insertBefore(tail, target, value))
                    cout << "Target not found\n";
                break;
            case 4:
                cin >> target >> value;
                if (!insertAfter(tail, target, value))
                    cout << "Target not found\n";
                break;
            case 5:
                cin >> value;
                if (!deleteValue(tail, value))
                    cout << "Value not found\n";
                break;
            case 6:
                cin >> value;
                search(tail, value);
                break;
            case 7:
                display(tail);
                break;
        }
    } while (choice != 0);
}#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

void insertBeginning(Node*& tail, int x) {
    Node* node = new Node(x);

    if (!tail) {
        tail = node;
        node->next = node;
    } else {
        node->next = tail->next;
        tail->next = node;
    }
}

void insertEnd(Node*& tail, int x) {
    insertBeginning(tail, x);
    tail = tail->next;
}

bool insertAfter(Node* tail, int target, int x) {
    if (!tail) return false;

    Node* head = tail->next;
    Node* cur = head;

    do {
        if (cur->data == target) {
            Node* node = new Node(x);
            node->next = cur->next;
            cur->next = node;

            if (cur == tail) tail = node;
            return true;
        }
        cur = cur->next;
    } while (cur != head);

    return false;
}

bool insertBefore(Node*& tail, int target, int x) {
    if (!tail) return false;

    Node* head = tail->next;

    if (head->data == target) {
        insertBeginning(tail, x);
        return true;
    }

    Node* cur = head;
    while (cur->next != head && cur->next->data != target)
        cur = cur->next;

    if (cur->next == head) return false;

    Node* node = new Node(x);
    node->next = cur->next;
    cur->next = node;
    return true;
}

bool deleteValue(Node*& tail, int value) {
    if (!tail) return false;

    Node* head = tail->next;
    Node* cur = head;
    Node* previous = tail;

    do {
        if (cur->data == value) {
            if (cur == tail && cur == head) {
                tail = nullptr;
            } else {
                previous->next = cur->next;
                if (cur == tail) tail = previous;
            }

            delete cur;
            return true;
        }

        previous = cur;
        cur = cur->next;
    } while (cur != head);

    return false;
}

void search(Node* tail, int value) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* head = tail->next;
    Node* cur = head;
    int position = 1;

    do {
        if (cur->data == value) {
            cout << "Found at position " << position << '\n';
            return;
        }
        cur = cur->next;
        position++;
    } while (cur != head);

    cout << "Not found\n";
}

void display(Node* tail) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* head = tail->next;
    Node* cur = head;

    do {
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);

    cout << "(back to head: " << head->data << ")\n";
}

int main() {
    Node* tail = nullptr;
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
                insertBeginning(tail, value);
                break;
            case 2:
                cin >> value;
                insertEnd(tail, value);
                break;
            case 3:
                cin >> target >> value;
                if (!insertBefore(tail, target, value))
                    cout << "Target not found\n";
                break;
            case 4:
                cin >> target >> value;
                if (!insertAfter(tail, target, value))
                    cout << "Target not found\n";
                break;
            case 5:
                cin >> value;
                if (!deleteValue(tail, value))
                    cout << "Value not found\n";
                break;
            case 6:
                cin >> value;
                search(tail, value);
                break;
            case 7:
                display(tail);
                break;
        }
    } while (choice != 0);
}
