// Given two strings, write a function to check if they are at most one edit away
// edits include replacing, inserting, or removing a char

#include <iostream>

using namespace std;

bool isOneReplacement(string a, string b) {
    // check if replacement
    // O(n)
    bool foundReplacement = false;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            if(foundReplacement) return false; // more than one replacement needed
            foundReplacement = true;
        }
    }

    return true;
}

bool isOneInsertion(string a, string b) {
    // check if insertion
    // O(n)
    int i = 0, j = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] != b[j]) {
            if(i != j) return false; // more than one insertion needed
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    return true;
}

bool solution(string a, string b) {
    // check if a replacement or insertion 
    // O(n)
    if(a.size() == b.size()) return isOneReplacement(a, b);
    else if(a.size() + 1 == b.size()) return isOneInsertion(a, b);
    else if(a.size() - 1 == b.size()) return isOneInsertion(b, a); // removal

    return false;
}

int main() {
    string foo = "foo";
    string fo = "fo";
    string bar = "bar";
    string baz = "baz";

    cout << solution(foo, fo) << endl;
    cout << solution(foo, bar) << endl;
    cout << solution(bar, baz) << endl;

    return 0;
}