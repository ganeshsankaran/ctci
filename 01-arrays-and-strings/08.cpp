// write an alg such that if an element in an MxN matrix is 0, its entire row and column are zeroed

#include <iostream>
#include <unordered_set>

using namespace std;

#define M 3
#define N 4

void solution(int matrix[M][N]) {
    // store sets rows and columns to zero
    // O(MN) time, O(M + N) space
    unordered_set<int> rows;
    unordered_set<int> cols;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for(unordered_set<int>::iterator it = rows.begin(); it != rows.end(); it++) {
        for(int j = 0; j < N; j++) {
            matrix[*it][j] = 0;
        }
    }

    for(unordered_set<int>::iterator it = cols.begin(); it != cols.end(); it++) {
        for(int i = 0; i < M; i++) {
            matrix[i][*it] = 0;
        }
    }
}

int main() {
    int matrix[M][N] = {{1, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 1, 1}};
    solution(matrix);

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}