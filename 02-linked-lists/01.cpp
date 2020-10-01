// write code to remove duplicates from an unsorted linked list

#include <iostream>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;

void solution1(LinkedList& l) {
    // store a set of values
    // O(n)
    unordered_set<int> seen;

    Node *curr = l.head, *prev = NULL;
    while(curr) {
        if(seen.find(curr->val) != seen.end()) {
            prev->next = curr->next;
            delete curr;
        }
        else {
            seen.insert(curr->val);
            prev = curr;
        }
        curr = prev->next;
    }
}

void solution2(LinkedList& l) {
    // run ahead and remove duplicates
    // O(n^2)
    Node *curr = l.head, *runner = l.head, *temp;

    while(curr) {
        runner = curr;
        while(runner && runner->next) {
            if(runner->next->val == curr->val) {
                temp = runner->next->next;
                delete runner->next;
                runner->next = temp;
            }
            runner = runner->next;
        }
        curr = curr->next;
    }
}

int main() {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);
    l.push_back(2);
    cout << l << endl;

    solution1(l);
    cout << l << endl;

    l = LinkedList();
    l.push_back(1);
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);
    l.push_back(2);
    
    solution2(l);
    cout << l << endl;

    return 0;
}