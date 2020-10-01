// Implement an algorithm to determine if a string has all unique characters

#include <iostream>
#include <unordered_set>

using namespace std;

bool solution1(string str) {
    // store seen chars in a set
    // O(n)
    unordered_set<char> seen;

    for(char c : str) {
        if(seen.find(c) != seen.end()) return false;
        else seen.insert(c);
    }

    return true;
}

bool solution2(string str) {
    // sort and compare adjacent chars
    // O(n log n)
    sort(str.begin(), str.end());

    for(int i = 1; i < str.size(); i++) {
        if(str[i] == str[i - 1]) return false;
    }

    return true;
}

int main() {
    string foo = "foo";
    string bar = "bar";

    cout << solution1(foo) << ',' << solution2(foo) << endl;
    cout << solution1(bar) << ',' << solution2(bar) << endl;
    return 0;
}