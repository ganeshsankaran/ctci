// implement a data structure that starts a new stack when the previous stack exceeds a threshold

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StackVector {
public:
    StackVector(int threshold) {
        stacks.push_back(stack<int>());
        index = 0;
        this->threshold = threshold;
    }

    void push(int val) {
        if(stacks[index].size() == threshold) {
            stacks.push_back(stack<int>());
            index++;
        }

        stacks[index].push(val);
    }

    void pop() {
        if(stacks[0].empty()) return;

        stacks[index].pop();
        if(stacks[index].empty()) {
            stacks.pop_back();
            index--;
        }
    }

    int top() {
        return stacks[index].top();
    }

private:
    vector<stack<int>> stacks;
    int index;
    int threshold;
};

int main() {
    StackVector s(2);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;

    return 0;
}