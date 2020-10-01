// given a boolean expression and a result value, implement a function to count how many
// ways of parenthesizing the expression such that it evaluates to the result

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int solution(string expr, bool result, unordered_map<string, int>& T) {
    // add parentheses around an operator like (...)&(...) and recurse on the left and right sides
    if(!expr.size()) return 0;
    if(expr.size() == 1) { // "0" or "1"
        if(expr == to_string(result)) return 1; 
        else return 0;
    }

    if(T.find(expr + to_string(result)) != T.end()) 
        return T[expr + to_string(result)];

    int ways = 0;

    for(int i = 1; i < expr.size(); i += 2) {
        string left = expr.substr(0, i);
        string right = expr.substr(i + 1);

        int ways_left_true = solution(left, true, T);
        int ways_left_false = solution(left, false, T);
        int ways_right_true = solution(right, true, T);
        int ways_right_false = solution(right, false, T);
        
        int ways_true;

        if(expr[i] == '&') 
            ways_true = ways_left_true * ways_right_true;
        else if(expr[i] == '|')
            ways_true = ways_left_true * ways_right_true 
                        + ways_left_true * ways_right_false 
                        + ways_left_false * ways_right_true;
        else if(expr[i] == '^')
            ways_true = ways_left_true * ways_right_false 
                        + ways_left_false * ways_right_true;


        int ways_false = (ways_left_true + ways_left_false) * (ways_right_true + ways_right_false) // take all ways
                        - ways_true; // all ways - ways resulting in true
        
        if(result) ways += ways_true;
        else ways += ways_false;
    }

    T[expr + to_string(result)] = ways;
    return ways;
}

int main() {
    unordered_map<string, int> T;
    cout << solution("1^0|0|1", false, T) << endl;
    cout << solution("0&0&0&1^1|0", true, T) << endl;

    return 0;
}