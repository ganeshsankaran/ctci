// Given two strings, check if the first is a rotation of the other

#include <iostream>
#include <string>

using namespace std;

bool solution(string a, string b) {
    // check if b = yx is a substring of aa = xyxy
    // O(n)
    if(a.length() != b.length()) return false;

    string aa = a + a;
    return aa.find(b) != string::npos;

}

int main() {
    string foo = "foo";
    string bar = "bar";
    string oof = "oof";
    
    cout << solution(foo, bar) << endl;
    cout << solution(foo, oof) << endl;

    return 0;
}