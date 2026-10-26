#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) cout << "Stack is empty\n";
        else {
            cout << "Removed: " << q1.front() << '\n';
            q1.pop();
        }
    }

    void top() {
        if (q1.empty()) cout << "Stack is empty\n";
        else cout << "Top: " << q1.front() << '\n';
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.top();  // 30
    s.pop();  // 30
    s.top();  // 20
}
