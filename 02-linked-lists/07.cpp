// determine if two lists intersect

#include <iostream>
#include <unordered_set>
#include "LinkedList.h"

Node* solution1(LinkedList& l1, LinkedList& l2) {
    // maintain a set of nodes
    // O(n + m)
    if(l1.tail != l2.tail) return NULL;

    unordered_set<Node*> nodes;
    
    Node* curr = l1.head;
    while(curr) {
        nodes.insert(curr);
        curr = curr->next;
    }

    curr = l2.head;
    while(curr) {
        if(nodes.find(curr) != nodes.end()) return curr;
        curr = curr->next;
    }

    return NULL;
}

Node* solution2(LinkedList& l1, LinkedList& l2) {
    // traverse both lists until common node is found
    // O(min(n, m))
    if(l1.tail != l2.tail) return NULL;

    Node *p = l1.head, *q = l2.head;
    if(l1.size() > l2.size()) {
        for(int i = 0; i < l1.size() - l2.size(); i++) {
            p = p->next;
        }
    }
    else if(l2.size() > l1.size()) {
        for(int i = 0; i < l2.size() - l1.size(); i++) {
            q = q->next;
        }
    }

    while(p && q && p != q) {
        p = p->next;
        q = q->next;
    }

    if(p && q) return p;
    else return NULL;
}

int main() {
    LinkedList intersection;
    intersection.push_back(7);
    intersection.push_back(2);
    intersection.push_back(1);

    LinkedList l1;
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(5);
    l1.push_back(9);
    l1.append(intersection);

    LinkedList l2;
    l2.push_back(4);
    l2.push_back(6);
    Node* tail = l2.tail;
    l2.append(intersection);

    Node* node = solution1(l1, l2);
    cout << node->val << endl;
    node = solution2(l1, l2);
    cout << node->val << endl;

    // avoid double delete
    intersection.head = NULL;
    tail->next = NULL;
    return 0;
}