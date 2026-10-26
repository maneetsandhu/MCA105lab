#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) cout << "Stack is empty\n";
        else {
            cout << "Removed: " << q.front() << '\n';
            q.pop();
        }
    }

    void top() {
        if (q.empty()) cout << "Stack is empty\n";
        else cout << "Top: " << q.front() << '\n';
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
