// Given a BST with distinct elements, print all possible insertion orders that could have led to this tree

#include <list>
#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

void weave(list<int>& a, list<int>& b, list<int>& prefix, vector<list<int>>& weaved) {
    if(a.size() == 0 || b.size() == 0) {
       list<int> temp = prefix;
       temp.insert(temp.end(), a.begin(), a.end());
       temp.insert(temp.end(), b.begin(), b.end());
       weaved.push_back(temp);
       return;
    }

    int front;

    // take the front off of a, add it to the prefix, and revert
    front = a.front();
    a.pop_front();
    prefix.push_back(front);
    weave(a, b, prefix, weaved);
    prefix.pop_back();
    a.push_front(front);

    // take the front off b, add it to the prefix, and revert
    front = b.front();
    b.pop_front();
    prefix.push_back(front);
    weave(a, b, prefix, weaved);
    prefix.pop_back();
    b.push_front(front);
}

vector<list<int>> solution(Node* root) {
    vector<list<int>> orders;

    if(!root) {
        orders.push_back(list<int>());
        return orders;
    }

    list<int> prefix;
    prefix.push_back(root->val);

    vector<list<int>> left = solution(root->left);
    vector<list<int>> right = solution(root->right);

    for(list<int> l : left) {
        for(list<int> r : right) {
            vector<list<int>> weaved;
            weave(l, r, prefix, weaved);
            orders.insert(orders.begin(), weaved.begin(), weaved.end());
        }
    }

    return orders;
}

int main() {
    BinarySearchTree bst1;
    bst1.insert(4);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(3);
    bst1.insert(6);
    bst1.insert(5);
    bst1.insert(7);

    vector<list<int>> orders = solution(bst1.root);
    for(list<int> order : orders) {
        for(list<int>::iterator it = order.begin(); it != order.end(); it++) {
            cout << *it << ' ';
        }
        cout << endl;
    }

    return 0;
}