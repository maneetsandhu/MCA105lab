/*
 * Q7: Count the number of inversions in an array.
 * A pair (A[i], A[j]) is an inversion if i < j but A[i] > A[j].
 * Brute force is O(n^2). Below is an efficient O(n log n) solution
 * using a modified Merge Sort.
 */

#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j] means all remaining elements from i..mid
            // are also greater than arr[j] -> that many inversions
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return invCount;
}

long long mergeSortCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortCount(arr, temp, left, mid);
        invCount += mergeSortCount(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }
    return invCount;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    vector<int> temp(arr.size());

    long long result = mergeSortCount(arr, temp, 0, (int)arr.size() - 1);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
