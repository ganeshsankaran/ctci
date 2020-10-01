// write code to partition a linked list around a value x

#include <iostream>
#include "LinkedList.h"

using namespace std;

void solution(LinkedList& src, LinkedList& dest, int val) {
    // push lesser elements to front and greater elements to back
    // O(n)
    Node* curr = src.head;
    while(curr) {
        if(curr->val < val) dest.push_front(curr->val);
        else dest.push_back(curr->val);
        curr = curr->next;
    }
}

int main() {
    LinkedList l;
    l.push_back(3);
    l.push_back(5);
    l.push_back(8);
    l.push_back(5);
    l.push_back(10);
    l.push_back(2);
    l.push_back(1);

    LinkedList partitioned;
    solution(l, partitioned, 5);
    cout << partitioned << endl;

    return 0;
}