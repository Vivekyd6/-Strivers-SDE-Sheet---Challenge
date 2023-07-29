#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = m - 1;
    while (rowStart < rowEnd && colStart < colEnd) {
        int prev = mat[rowStart + 1][colStart];
        // Move elements of the first row from the remaining rows
        for (int i = colStart; i <= colEnd; i++) {
            int curr = mat[rowStart][i];
            mat[rowStart][i] = prev;
            prev = curr;
        }
        rowStart++;
        // Move elements of the last column from the remaining columns

        for (int i = rowStart; i <= rowEnd; i++) {
            int curr = mat[i][colEnd];
            mat[i][colEnd] = prev;
            prev = curr;
        }
        colEnd--;
        // Move elements of the last row from the remaining rows
        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                int curr = mat[rowEnd][i];
                mat[rowEnd][i] = prev;
                prev = curr;
            }
            rowEnd--;
        }

        // Move elements of the first column from the remaining columns
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                int curr = mat[i][colStart];
                mat[i][colStart] = prev;
                prev = curr;
            }
            colStart++;
        }
    }
}