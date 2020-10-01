// design an alg to find the first common ancestor of two nodes in a binary tree

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

bool contains(Node* root, int val) {
    if(!root) return false;
    if(root->val == val) return true;

    return contains(root->left, val) || contains(root->right, val);
}

Node* solution(Node* root, int p, int q) {
    // keep checking if both p and q are in the same subtree or not
    // O(n)
    if(!contains(root, p) || !contains(root, q)) return NULL;

    if(contains(root->left, p) != contains(root->left, q)) return root; // p and q on different sides of root
    else {
        if(contains(root->left, p)) return solution(root->left, p, q); // p and q both on left
        else return solution(root->right, p, q);
    }
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

    cout << solution(bst1.root, 5, 7)->val << endl;

    return 0;
}