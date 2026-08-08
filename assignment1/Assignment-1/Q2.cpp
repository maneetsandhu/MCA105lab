#include <iostream>

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7; // Initial array size

    // Step 1: Pick an element
    for (int i = 0; i < n; i++) {
        // Step 2: Check all next elements for duplicates
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                // Step 3: Shift items left to erase duplicate
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; // Decrease array size
                j--; // Check the same index again for shifted value
            }
        }
    }

    // Print unique elements
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    return 0;
}
