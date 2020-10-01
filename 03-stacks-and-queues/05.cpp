// write a program to sort a stack such that the minimum elements are on the top

#include <iostream>
#include <stack>

using namespace std;

ostream& operator<<(ostream& os, stack<int> s) {
    while(!s.empty()) {
        os << s.top() << ' ';
        s.pop();
    }
    
    return os;
}

void solution(stack<int>& s) {
    // O(n^2)
    if(s.empty()) return;
    
    stack<int> temp;
    temp.push(s.top());
    s.pop();

    while(!s.empty()) {
        int top = s.top();
        s.pop();

        while(!temp.empty() && top > temp.top()) {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(top);
    }

    s = temp;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(1);
    s.push(5);
    cout << s << endl;

    solution(s);
    cout << s << endl;

    return 0;
}