// return number of ways of representing n cents

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int>& denoms) {
    // subtract each denomination and calculate number of ways to represent the difference
    // O(n)
    int T[n + 1];
    T[0] = 1;
    for(int i = 1; i < n + 1; i++) {
        T[i] = 0;
    }

    for(int i = 1; i < denoms.size(); i++) {
        for(int j = denoms[i]; j <= n; j++) {
            T[j] += T[j - denoms[i]];
        }
    }

    return T[n];
}

int main() {
    vector<int> denoms;
    denoms.push_back(25);
    denoms.push_back(10);
    denoms.push_back(5);
    denoms.push_back(1);
    
    cout << solution(16, denoms) << endl;

    return 0;
}