// Given two strings, write a method to decide if one is a permutation of the other

#include <iostream>
#include <unordered_map>

using namespace std;

bool solution1(string a, string b) {
    // sort and compare
    // O(n log n)

    if(a.size() != b.size()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

bool solution2(string a, string b) {
    // count chars
    // O(n)
    if(a.size() != b.size()) return false;

    unordered_map<char, int> counts;

    for(char c : a) {
        if(counts.find(c) == counts.end()) counts[c] = 1;
        else counts[c]++;
    }

    for(char c : b) {
        if(counts.find(c) == counts.end()) return false;
        else counts[c]--;
    }

    for(unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); it++) {
        if(it->second != 0) return false;
    }

    return true;
}

int main() {
    string foo = "foo";
    string bar = "bar";
    string oof = "oof";

    cout << solution1(foo, bar) << ',' << solution2(foo, bar) << endl;
    cout << solution1(foo, oof) << ',' << solution2(foo, oof) << endl;
    return 0;
}