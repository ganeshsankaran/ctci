// implement a queue using two stacks

#include <iostream>
#include <stack>

using namespace std;

class TwoStackQueue {
public:
    void push(int val) {
        while(!s.empty()) {
            temp.push(s.top());
            s.pop();
        }

        s.push(val);

        while(!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }

    void pop() {
        s.pop();
    }

    int front() {
        return s.top();
    }

private:
    stack<int> s;
    stack<int> temp;
};

int main() {
    TwoStackQueue q;
    q.push(1);
    q.push(2);
    cout << q.front() << endl;

    return 0;
}