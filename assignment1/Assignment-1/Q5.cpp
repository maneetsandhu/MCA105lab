#include <iostream>

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        int colSum = 0;
        
        for (int j = 0; j < 3; j++) {
            rowSum += mat[i][j]; 
            colSum += mat[j][i]; 
        }
        
        std::cout << "Sum of Row " << i + 1 << " = " << rowSum << "\n";
        std::cout << "Sum of Column " << i + 1 << " = " << colSum << "\n\n";
    }

    return 0;
}
