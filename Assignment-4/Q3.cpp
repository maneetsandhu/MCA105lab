#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;
    queue<int> q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    if (n % 2 != 0) {
        cout << "Please enter an even number of elements\n";
        return 0;
    }

    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        cout << firstHalf.front() << ' ';
        firstHalf.pop();

        cout << q.front() << ' ';
        q.pop();
    }
}
