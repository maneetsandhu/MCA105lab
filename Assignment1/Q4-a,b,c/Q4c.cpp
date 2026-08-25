#include <iostream>

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int T[3][2]; 

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            T[j][i] = A[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) std::cout << T[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}
