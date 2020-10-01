// given two sorted arrays A and B, merge B into A

#include <iostream>

using namespace std;

void solution(int* A, int*B, int a, int b) {
    // start from the end and keep moving the indices
    int i = a + b - 1;
    a--;
    b--;

    while(b >= 0) {
        if(a >= 0 && A[a] > B[b]) {
            A[i] = A[a];
            a--;
        }
        else {
            A[i] = B[b];
            b--;
        }
        i--;
    }
}

int main() {
    int A[10] = {1, 2, 4, 5, 8, 12};
    int B[4] = {3, 6, 9, 11};

    solution(A, B, 6, 4);
    for(int i = 0; i < 10; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;

    return 0;
}