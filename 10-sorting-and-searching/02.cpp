// sort an array of strings such that all anagrams are next to each other

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class AnagramComparator {
public:
    bool operator()(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

void solution1(vector<string>& strings) {
    // NOT WORKING
    // O(s log s * n log n) for sorting each string and the array itself
    sort(strings.begin(), strings.end(), AnagramComparator());
}

vector<string> solution2(vector<string> strings) {
    // O(n * s log s)
    unordered_map<string, vector<string>> anagrams;

    for(string str : strings) {
        string temp = str;
        sort(temp.begin(), temp.end());
        if(anagrams.find(temp) == anagrams.end()) anagrams[temp] = vector<string>(1, str);
        else anagrams[temp].push_back(str);
    }

    strings = vector<string>();
    for(unordered_map<string, vector<string>>::iterator it = anagrams.begin(); it != anagrams.end(); it++) {
        for(int i = 0; i < it->second.size(); i++) {
            strings.push_back(it->second[i]);
        }
    }
    
    return strings;
}

int main() {
    vector<string> strings1;
    strings1.push_back("foo");
    strings1.push_back("bar");
    strings1.push_back("oof");
    strings1.push_back("baz");
    strings1.push_back("bra");
    
    vector<string> strings2 = strings1;

    solution1(strings1);

    for(string str : strings1) {
        cout << str << endl;
    }

    cout << endl;
    
    strings2 = solution2(strings2);
    for(string str : strings2) {
        cout << str << endl;
    }

    return 0;
}