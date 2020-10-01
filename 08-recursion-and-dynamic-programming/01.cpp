// implement a method to count how many possible ways a child can run up the stairs with 1, 2, or 3 stair steps

#include <iostream>

using namespace std;

int solution(int n) {
    // T(n) = T(n - 1) + T(n - 2) + T(n - 3)
    // O(n)
    int T[max(4, n + 1)];
    T[0] = 0;
    T[1] = 1; // (1)
    T[2] = 2; // (1, 1), (2)
    T[3] = 4; // (1, 1, 1), (1, 2), (2, 1), (3)
    
    for(int i = 4; i <= n; i++) {
        T[i] = T[i - 1] + T[i - 2] + T[i - 3];
    }

    return T[n];
}

int main() {
    cout << solution(5) << endl;

    return 0;
}