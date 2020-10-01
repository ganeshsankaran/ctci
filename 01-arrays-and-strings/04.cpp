// Given a string, write a function to check if it is a permutation of a palindrome

#include <iostream>
#include <unordered_map>

using namespace std;

bool solution(string str) {
    // check if at most one character appears an odd number of times
    // O(n)
    unordered_map<char, int> counts;

    for(char c : str) {
        if(counts.find(c) == counts.end()) counts[c] = 1;
        else counts[c]++;
    }

    int odd = 0;
    for(unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); it++) {
        if(it->second % 2 != 0) {
            odd++;
            if(odd > 1) return false;
        }
    }

    return true;
}

int main() {
    string foo = "foo";
    string bar = "bar";

    cout << solution(foo) << endl;
    cout << solution(bar) << endl;
    
    return 0;
}