// find all permutations of a string of unique chars

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string s) {
    // put the first char at different positions in the permutations of the remaining chars
    // O(n!)
    if(s.size() == 1) return vector<string>(1, s);

    vector<string> perms;

    vector<string> _perms = solution(s.substr(1));
    for(string t : _perms) {
        for(int i = 0; i <= t.length(); i++) {
            string temp = t;
            temp.insert(temp.begin() + i, s[0]);
            perms.push_back(temp);
        }
    }

    return perms;
}

int main() {
    vector<string> perms = solution("bar");
    for(string perm : perms) {
        cout << perm << endl;
    }

    return 0;
}