// given a binary tree, design an alg that creates lists of all the nodes at each depth

#include <list>
#include <iostream>
#include <queue>
#include <unordered_map>
#include "BinarySearchTree.h"

using namespace std;

unordered_map<int, list<int>> solution(BinarySearchTree& bst) {
    // do a BFS keeping track of depth
    // O(n)
    unordered_map<int, list<int>> nodes;

    queue<pair<int, Node*>> q;
    q.push(pair<int, Node*>(0, bst.root));

    Node* curr;
    int depth;

    while(!q.empty()) {
        depth = q.front().first;
        curr = q.front().second;
        q.pop();

        if(nodes.find(depth) == nodes.end()) {
            nodes[depth] = list<int>();
        }
        nodes[depth].push_back(curr->val);

        if(curr->left) q.push(pair<int, Node*>(depth + 1, curr->left));
        if(curr->right) q.push(pair<int, Node*>(depth + 1, curr->right));
    }

    return nodes;
}

int main() {
    
    BinarySearchTree bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(6);
    bst.insert(5);
    bst.insert(7);

    unordered_map<int, list<int>> nodes = solution(bst);

    for(unordered_map<int, list<int>>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        cout << it->first << ": ";
        for(list<int>::iterator j = it->second.begin(); j != it->second.end(); j++) {
            cout << *j << ' ';
        }
        cout << endl;
    }

    return 0;
}