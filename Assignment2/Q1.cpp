#include <iostream>
#include <vector>
using namespace std;

// Linear Search: O(n)
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == key)
            return i; // index found
    }
    return -1; // not found
}

// Binary Search: O(log n) - vector must be sorted
int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int main() {
    vector<int> arr = {11, 12, 22, 25, 34, 64, 90}; // sorted array
    int key = 25;

    int li = linearSearch(arr, key);
    int bi = binarySearch(arr, key);

    if (li != -1)
        cout << "Linear Search: Element " << key << " found at index " << li << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    if (bi != -1)
        cout << "Binary Search: Element " << key << " found at index " << bi << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}