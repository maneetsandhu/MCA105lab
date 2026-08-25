/*
 * Q3: Find the Missing Number in a Sorted Array
 * Array contains n-1 distinct integers in range [1, n], one number is missing.
 * (a) Linear time approach
 * (b) Binary Search approach
 */

#include <iostream>
#include <vector>
using namespace std;

// (a) Linear time: value should equal index+1 in a correctly filled array
int findMissingLinear(const vector<int>& arr) {
    int n = (int)arr.size(); // size of array (n-1 elements), full range is 1..n
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1; // mismatch found -> this is the missing number
    }
    return n + 1; // missing number is the last one
}

// (b) Binary Search: exploit the fact that arr[mid] == mid+1 until the gap
int findMissingBinary(const vector<int>& arr) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1; // no mismatch yet, missing number is to the right
        } else {
            high = mid - 1; // mismatch found, missing number is here or left
        }
    }
    return low + 1;
}

int main() {
    // Range is 1..8, number 5 is missing, array has 7 elements
    vector<int> arr = {1, 2, 3, 4, 6, 7, 8};

    cout << "(a) Missing number (Linear): " << findMissingLinear(arr) << endl;
    cout << "(b) Missing number (Binary Search): " << findMissingBinary(arr) << endl;

    return 0;
}