#include <iostream>
#include <algorithm> 

void rotateLeft(int arr[], int n, int k) {
    k = k % n; 
    std::reverse(arr, arr + k);      
    std::reverse(arr + k, arr + n);   
    std::reverse(arr, arr + n);       
}

void rotateRight(int arr[], int n, int k) {
    k = k % n;
    std::reverse(arr, arr + n);    
    std::reverse(arr, arr + k);      
    std::reverse(arr + k, arr + n);    
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    int A1[] = {1, 2, 3, 4, 5}, A2[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    rotateLeft(A1, n, k);
    std::cout << "Left Rotation: ";
    printArray(A1, n);

    rotateRight(A2, n, k);
    std::cout << "Right Rotation: ";
    printArray(A2, n); 

    return 0;
}
