// write a method to return the power set

#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(int* A, int n) {
    // generate 2^n bitsets telling which elements to add to the set
    // O(n * 2^n)
    vector<vector<int>> P;

    for(int i = 0; i < (1 << n); i++) {
        bitset<sizeof(int) * 8> binary(i);
        vector<int> S;

        for(int j = 0; j < n; j++) {
            if(binary[j]) S.push_back(A[j]);
        }

        P.push_back(S);
    }

    return P;
}

int main() {
    int A[] = {1, 2, 3, 4};
    vector<vector<int>> P = solution(A, 4);

    for(int i = 0; i < P.size(); i++) {
        for(int j = 0; j < P[i].size(); j++) {
            cout << P[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}