#include <iostream>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int i = 0; i < n / 2; i++) {
        std::swap(arr[i], arr[n - 1 - i]); 
    }

    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    return 0;
}
