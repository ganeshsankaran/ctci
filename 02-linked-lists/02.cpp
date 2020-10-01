// implement an algorithm to find the kth to last element of a linked list

#include <iostream>
#include "LinkedList.h"

using namespace std;

Node* solution1(LinkedList& l, int k) {
    // if length is known
    // O(n)
    if(k > l.size()) return NULL;

    Node* curr = l.head;
    for(int i = 0; i < l.size() - k; i++) {
        curr = curr->next;
    }

    return curr;
}

Node* solution2(LinkedList& l, int k) {
    // run ahead k steps
    // when runner reaches end, curr is at kth from last node
    // O(n)
    Node *curr = l.head, *runner = l.head;

    for(int i = 0; i < k; i++) {
        if(!runner) return NULL;
        runner = runner->next;
    }

    while(runner) {
        curr = curr->next;
        runner = runner->next;
    }

    return curr;
}

int main() {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    cout << solution1(l, 3)->val << ',' << solution2(l, 3)->val << endl;

    return 0;
}