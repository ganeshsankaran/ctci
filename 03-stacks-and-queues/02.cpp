// design a stack which has a function which returns the minimum element

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
        mins.push(INT_MAX);
    }

    void push(int val) {
        s.push(val);
        if(val <= mins.top()) mins.push(val);
    }

    void pop() {
        if(s.empty()) return;

        int val = s.top();
        s.pop();
        if(val == mins.top()) mins.pop();
    }

    int min() {
        return mins.top();
    }

private:
    stack<int> s;
    stack<int> mins;
};

int main() {
    MinStack s;
    s.push(5);
    s.push(6);
    cout << s.min() << endl;
    s.push(3);
    s.push(3);
    s.push(7);
    s.pop();
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;

    return 0;
}