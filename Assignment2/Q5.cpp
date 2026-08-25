/*
 * Q5: Efficient storage for special matrices using a 1D vector
 * instead of a full 2D matrix (rows x cols).
 *
 * (a) Diagonal Matrix        -> store only n diagonal elements
 * (b) Tri-diagonal Matrix    -> store only the 3 diagonals (~3n elements)
 * (c) Lower Triangular Matrix-> store only elements where row >= col
 * (d) Upper Triangular Matrix-> store only elements where row <= col
 * (e) Symmetric Matrix       -> store only one triangle (upper or lower)
 */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int N = 4; // size of the square matrix (N x N)
using Matrix = vector<vector<int>>;

/* ---------- (a) Diagonal Matrix ---------- */
vector<int> diagonalStore(const Matrix& mat) {
    vector<int> diag(N);
    for (int i = 0; i < N; i++)
        diag[i] = mat[i][i];
    return diag;
}

/* ---------- (b) Tri-diagonal Matrix ---------- */
// Non-zero elements only on main diagonal + one above + one below
vector<int> triDiagonalStore(const Matrix& mat) {
    vector<int> tri;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (abs(i - j) <= 1)
                tri.push_back(mat[i][j]);
    return tri;
}

/* ---------- (c) Lower Triangular Matrix ---------- */
// Elements exist only where row >= col. Store row-wise.
vector<int> lowerTriangularStore(const Matrix& mat) {
    vector<int> arr;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            arr.push_back(mat[i][j]);
    return arr;
}
// Index formula to directly access element (i,j) with i>=j: i*(i+1)/2 + j

/* ---------- (d) Upper Triangular Matrix ---------- */
// Elements exist only where row <= col. Store row-wise.
vector<int> upperTriangularStore(const Matrix& mat) {
    vector<int> arr;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            arr.push_back(mat[i][j]);
    return arr;
}

/* ---------- (e) Symmetric Matrix ---------- */
// mat[i][j] == mat[j][i], so store only the lower (or upper) triangle
vector<int> symmetricStore(const Matrix& mat) {
    vector<int> arr;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            arr.push_back(mat[i][j]);
    return arr;
}

void printVec(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    Matrix mat = {
        {1, 2, 0, 0},
        {2, 3, 4, 0},
        {0, 4, 5, 6},
        {0, 0, 6, 7}
    }; // example: symmetric & tri-diagonal matrix

    cout << "(a) Diagonal elements: ";
    printVec(diagonalStore(mat));

    cout << "(b) Tri-diagonal elements: ";
    printVec(triDiagonalStore(mat));

    cout << "(c) Lower triangular elements: ";
    printVec(lowerTriangularStore(mat));

    cout << "(d) Upper triangular elements: ";
    printVec(upperTriangularStore(mat));

    cout << "(e) Symmetric matrix (lower half) elements: ";
    printVec(symmetricStore(mat));

    return 0;
}