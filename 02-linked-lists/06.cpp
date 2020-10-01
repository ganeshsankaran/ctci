// implement a function to check if a linked list is a palindrome

#include <iostream>
#include "LinkedList.h"

using namespace std;

bool solution(LinkedList& l) {
    // reverse first half of elements into another linked list and compare
    // O(n)
    LinkedList reverse;
    Node *curr = l.head, *runner = l.head;

    while(runner && runner->next) {
        reverse.push_front(curr->val);
        curr = curr->next;
        runner = runner->next->next;
    }

    if(runner) curr = curr->next; // handle odd length
    
    Node* p = reverse.head;
    while(curr) {
        if(curr->val != p->val) return false;
        
        curr = curr->next;
        p = p->next;
    }

    return true;
}

int main() {
    LinkedList l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(1);

    LinkedList l2;
    l2.push_back(1);

    LinkedList l3;
    l3.push_back(1);
    l3.push_back(2);

    cout << solution(l1) << endl;
    cout << solution(l2) << endl;
    cout << solution(l3) << endl;
    
    return 0;
}