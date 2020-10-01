// find all permutations of a string with duplicate chars

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_set<string> solution1(string s) {
    // put the first char at different positions in the permutations of the remaining chars
    // maintain a set of unique perms
    // O(n!)
    unordered_set<string> perms;

    if(s.size() == 1) {
        perms.insert(s);
        return perms;
    }

    unordered_set<string> _perms = solution1(s.substr(1));
    for(string t : _perms) {
        for(int i = 0; i <= t.length(); i++) {
            string temp = t;
            temp.insert(temp.begin() + i, s[0]);
            perms.insert(temp);
        }
    }

    return perms;
}

vector<string> solution2(string prefix, int n, unordered_map<char, int>& freqs) {
    // keep track of the frequencies of chars remaining
    // O(n!)
    if(!n) return vector<string>(1, prefix);

    vector<string> perms;
    
    for(unordered_map<char, int>::iterator it = freqs.begin(); it != freqs.end(); it++) {
        if(it->second > 0) {
            it->second--;
            
            vector<string> _perms = solution2(prefix + it->first, n - 1, freqs);
            perms.insert(perms.end(), _perms.begin(), _perms.end());

            it->second++;
        }
    }

    return perms;
}

int main() {
    string foo = "foo";
    unordered_map<char, int> freqs;

    for(char c : foo) {
        if(freqs.find(c) == freqs.end()) freqs[c] = 1;
        else freqs[c]++;
    }

    unordered_set<string> perms1 = solution1(foo);
    for(string perm : perms1) {
        cout << perm << endl;
    }

    cout << endl;
    
    vector<string> perms2 = solution2("", foo.size(), freqs);
    for(string perm : perms2) {
        cout << perm << endl;
    }

    return 0;
}