// implement a method to perform basic string compression

#include <iostream>
#include <string>

using namespace std;

string solution(string str) {
    // O(n)
    string compressed = "";

    int consecutive = 1;
    
    for(int i = 1; i < str.size(); i++) {
        if(str[i - 1] == str[i]) {
            consecutive++;
        }
        else {
            compressed.append(str[i - 1] + to_string(consecutive));
            consecutive = 1;
        }
    }

    if(consecutive > 0) {
        compressed.append(str[str.size() - 1] + to_string(consecutive));
    }

    if(compressed.size() < str.size()) return compressed;
    else return str;
}

int main() {
    string abcd = "abcd";
    string aaaaaaabbbbcccccd = "aaaaaaabbbbcccccd";

    cout << solution(abcd) << endl;
    cout << solution(aaaaaaabbbbcccccd) << endl;

    return 0;
}