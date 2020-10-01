// given an M x N matrix with sorted rows and columns, write a method to find an element

#include <iostream>

#define M 4
#define N 4

using namespace std;

int* solution(int matrix[M][N], int val) {
    // keep checking beginnings/endings of rows/cols
    // O(M + N)
    int row = 0;
    int col = N - 1;

    while(row < M && col >= 0) {
        if(matrix[row][col] == val) return &matrix[row][col];
        else if(matrix[row][col] > val) col--; // move left if start of col is greater
        else row++; // move down if start of row is less
    }

    return NULL;
}

int main() {
    int matrix[M][N] = {{15, 20, 40, 85}, 
                        {20, 35, 80, 95}, 
                        {30, 55, 95, 105},
                        {40, 80, 100, 120}};
    int* p = solution(matrix, 55);
    cout << *p << endl;

    return 0;
}