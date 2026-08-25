/*
 * Q8: Count the total number of distinct elements in an array of length n.
 * Approach: use a set, which automatically stores only unique values.
 * Time: O(n log n)
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countDistinct(const vector<int>& arr) {
    set<int> s(arr.begin(), arr.end()); // duplicates are automatically discarded
    return (int)s.size();
}

int main() {
    vector<int> arr = {10, 20, 20, 10, 30, 40, 40};

    cout << "Number of distinct elements: " << countDistinct(arr) << endl;

    return 0;
}
