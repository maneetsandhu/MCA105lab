/*
 * Q6: Sparse Matrix operations using Triplet representation
 * Each non-zero element is stored as (row, col, value).
 * triplet[0] = {rows, cols, number_of_nonzero_terms}
 * triplet[1..n] = {row, col, value} for each non-zero element
 *
 * (a) Transpose
 * (b) Addition
 * (c) Multiplication
 */

#include <iostream>
#include <vector>
using namespace std;

using Triplet = vector<vector<int>>; // each row: {row, col, value}

/* ---------- (a) Transpose of a sparse matrix ---------- */
Triplet transpose(const Triplet& a) {
    int rows = a[0][0], cols = a[0][1], terms = a[0][2];
    Triplet result;
    result.push_back({cols, rows, terms});

    // For every column of 'a', find matching triplets in row order of result
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= terms; i++) {
            if (a[i][1] == c) {
                result.push_back({a[i][1], a[i][0], a[i][2]}); // swap row/col
            }
        }
    }
    return result;
}

/* ---------- (b) Addition of two sparse matrices ---------- */
Triplet addSparse(const Triplet& a, const Triplet& b) {
    int aRows = a[0][0], aCols = a[0][1], aTerms = a[0][2];
    int bTerms = b[0][2];
    Triplet result;
    result.push_back({0, 0, 0}); // placeholder header, filled at the end

    int i = 1, j = 1;
    while (i <= aTerms && j <= bTerms) {
        long posA = (long)a[i][0] * aCols + a[i][1];
        long posB = (long)b[j][0] * aCols + b[j][1];

        if (posA < posB) {
            result.push_back(a[i]);
            i++;
        } else if (posA > posB) {
            result.push_back(b[j]);
            j++;
        } else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0)
                result.push_back({a[i][0], a[i][1], sum});
            i++; j++;
        }
    }
    while (i <= aTerms) { result.push_back(a[i]); i++; }
    while (j <= bTerms) { result.push_back(b[j]); j++; }

    result[0] = {aRows, aCols, (int)result.size() - 1};
    return result;
}

/* ---------- (c) Multiplication of two sparse matrices ---------- */
Triplet multiplySparse(const Triplet& a, const Triplet& b) {
    int aRows = a[0][0], aTerms = a[0][2];
    int bCols = b[0][1], bTerms = b[0][2];
    Triplet result;
    result.push_back({0, 0, 0}); // placeholder header

    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            int sum = 0;
            for (int x = 1; x <= aTerms; x++) {
                if (a[x][0] == i) { // element belongs to row i of A
                    for (int y = 1; y <= bTerms; y++) {
                        if (b[y][0] == a[x][1] && b[y][1] == j) {
                            sum += a[x][2] * b[y][2];
                        }
                    }
                }
            }
            if (sum != 0)
                result.push_back({i, j, sum});
        }
    }
    result[0] = {aRows, bCols, (int)result.size() - 1};
    return result;
}

void printSparse(const string& label, const Triplet& m) {
    cout << label << " (rows=" << m[0][0] << ", cols=" << m[0][1]
         << ", terms=" << m[0][2] << "):" << endl;
    for (int i = 1; i <= m[0][2]; i++)
        cout << "  (" << m[i][0] << ", " << m[i][1] << ") = " << m[i][2] << endl;
}

int main() {
    // Example sparse matrix A (3x3): A[0][0]=1, A[1][2]=2, A[2][1]=3
    Triplet A = {
        {3, 3, 3},
        {0, 0, 1},
        {1, 2, 2},
        {2, 1, 3}
    };

    // Example sparse matrix B (3x3): B[0][0]=4, B[1][2]=5, B[2][1]=6
    Triplet B = {
        {3, 3, 3},
        {0, 0, 4},
        {1, 2, 5},
        {2, 1, 6}
    };

    printSparse("(a) Transpose of A", transpose(A));
    printSparse("(b) A + B", addSparse(A, B));
    printSparse("(c) A * B", multiplySparse(A, B));

    return 0;
}