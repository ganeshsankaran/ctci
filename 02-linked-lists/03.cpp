// implement an alg to delete a node in the middle of a linked list given a pointer to that node

#include <iostream>
#include "LinkedList.h"

using namespace std;

void solution(Node* p) {
    // copy next node over and delete next node
    // O(1)
    if(!p->next) {
        return;
    }

    p->val = p->next->val;
    Node* temp = p->next->next;
    delete p->next;
    p->next = temp;
}

int main() {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    Node* p = l.tail;
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    cout << l << endl;

    solution(p);
    cout << l << endl;

    return 0;
}