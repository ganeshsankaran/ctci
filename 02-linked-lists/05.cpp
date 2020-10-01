// write a function that adds two numbers in linked lists (reversed digits) and returns the sum as a linked list

#include <iostream>
#include "LinkedList.h"

void solution(LinkedList& a, LinkedList& b, LinkedList& sum) {
    bool carry = false;

    Node *p = a.head, *q = b.head;

    while(p && q) {
        sum.push_back((p->val + q->val + carry) % 10);
        if(p->val + q->val + carry > 9) carry = true;
        else carry = false;

        p = p->next;
        q = q->next;
    }

    while(p) {
        sum.push_back((p->val + carry) % 10);
        if(p->val + carry > 9) carry = true;
        else carry = false;

        p = p->next;
    }

    while(q) {
        sum.push_back((q->val + carry) % 10);
        if(q->val + carry > 9) carry = true;
        else carry = false;

        q = q->next;
    }

    if(carry) {
        sum.push_back(1);
    }
}

int main() {
    LinkedList a; // 617
    a.push_back(7);
    a.push_back(1);
    a.push_back(6);

    LinkedList b; // 895
    b.push_back(5);
    b.push_back(9);
    b.push_back(8);

    LinkedList sum;
    solution(a, b, sum);
    cout << sum << endl;

    return 0;
}