// print all valid combinations of n pairs of parentheses

#include <iostream>
#include <unordered_set>
#include <vector>

#define N 5

using namespace std;

unordered_set<string> solution1(int n) {
    // for a valid string S, take ()S, S(), and (S)
    unordered_set<string> combs;
    
    if(n == 0) {
        combs.insert("");
        return combs;
    }

    unordered_set<string> _combs = solution1(n - 1);
    for(string s : _combs) {
        combs.insert("()" + s);
        combs.insert(s + "()");
        combs.insert('(' + s + ')');
    }

    return combs;
}

vector<string> solution2(int lefts, int rights, char* T, int i = 0) {
    // keep generating parentheses
    // add a ( if lefts remain
    // add a ) if rights remain and there are more lefts than rights
    vector<string> combs;

    if(lefts < 0 || lefts > rights) return vector<string>();

    if(lefts == 0 && rights == 0) {
        combs.push_back(string(T, T + 2 * N));
    }
    else {
        T[i] = '(';
        vector<string> _combs = solution2(lefts - 1, rights, T, i + 1);
        combs.insert(combs.end(), _combs.begin(), _combs.end());

        T[i] = ')';
        _combs = solution2(lefts, rights - 1, T, i + 1);
        combs.insert(combs.end(), _combs.begin(), _combs.end());
    }

    return combs;
}

int main() {
    unordered_set<string> combs1 = solution1(N);
    for(string s : combs1) {
        cout << s << endl;
    }

    cout << endl;

    char T[2 * N];
    vector<string> combs2 = solution2(N, N, T);
    for(string s : combs2) {
        cout << s << endl;
    }
    
    return 0;
}