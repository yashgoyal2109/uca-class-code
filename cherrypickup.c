#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxcherry(char matrix[][4], int i, int j, int n, int m) {
    if(i >= n || j >= m) {
        return 0;
    }
    if(i == n-1 && j == m-1) {
        return matrix[i][j] - '0';
    }
    int c1 = maxcherry(matrix, i+1, j, n, m);
    int c2 = maxcherry(matrix, i, j+1, n, m);
    int curr = matrix[i][j] - '0';

    return curr + max(c1, c2);
}

int main() {
    char matrix[4][4] = {
        {'1', '1', '1', '1'},
        {'1', '1', '1', '1'},
        {'1', '1', '1', '1'},
        {'0', '0', '0', '0'}
    };
    int n = 4;
    int m = 4;
    int ans = maxcherry(matrix, 0, 0, n, m);
    printf("%d", ans);
    return 0;
}