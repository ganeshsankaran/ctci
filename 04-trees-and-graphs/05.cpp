// write a function to check if a binary tree is a BST

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

bool solution1(Node* root, int& val) {
    // do an inorder traversal and check if vals are ascending (assume no duplicates)
    // O(n)
    if(!root) return true;

    if(!solution1(root->left, val)) return false;

    if(root->val < val) return false; // not ascending
    else val = root->val;

    if(!solution1(root->right, val)) return false;
    
    return true;
}

bool solution2(Node* root, int min, int max) {
    // check if all vals down the tree are between min and max
    // O(n)
    if(!root) return true;

    if(root->val < min || root->val > max) return false;
    if(!solution2(root->left, min, root->val)) return false;
    if(!solution2(root->right, root->val, max)) return false;

    return true;
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

    BinarySearchTree bst2;
    bst2.insert(4);
    bst2.insert(2);
    bst2.insert(1);
    bst2.insert(3);
    bst2.insert(6);
    bst2.insert(5);
    bst2.insert(7);
    bst2.root->left->val = INT_MAX;

    int val, min, max;
    cout << solution1(bst1.root, val = INT_MIN) << ',' << solution2(bst1.root, min = INT_MIN, max = INT_MAX) << endl;
    cout << solution1(bst2.root, val = INT_MIN) << ',' << solution2(bst2.root, min = INT_MIN, max = INT_MAX) << endl;

    return 0;
}