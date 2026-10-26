#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int count[256] = {};
    queue<char> q;

    for (char c : s) {
        count[(unsigned char)c]++;
        q.push(c);

        while (!q.empty() && count[(unsigned char)q.front()] > 1)
            q.pop();

        if (q.empty()) cout << "-1 ";
        else cout << q.front() << ' ';
    }
}
