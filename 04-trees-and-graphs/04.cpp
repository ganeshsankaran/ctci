// implement a function to check if a binary tree is balanced

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int height1(Node* root) {
    if(!root) return -1;

    return max(height1(root->left), height1(root->right)) + 1;
}

int height2(Node* root) {
    if(!root) return -1;

    int left = height2(root->left);
    int right = height2(root->right);

    if(left == INT_MIN || right == INT_MIN) return INT_MIN; // pass up "error""

    if(abs(left - right) > 1) return INT_MIN; // throw "error"
    else return max(left, right) + 1;
}

bool solution1(Node* root) {
    // check height difference for each node recursively
    // O(n^2) worst, O(n log n) avg
    if(!root) return true;

    if(abs(height1(root->left) - height1(root->right)) > 1) return false;
    else return solution1(root->left) && solution1(root->right);
}

bool solution2(Node* root) {
    // check balance while checking height differences
    // O(n)
    return height2(root) != INT_MIN;
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
    bst2.insert(1);
    bst2.insert(2);
    bst2.insert(3);
    bst2.insert(4);
    bst2.insert(5);
    bst2.insert(6);
    bst2.insert(7);

    cout << solution1(bst1.root) << ',' << solution2(bst1.root) << endl;
    cout << solution1(bst2.root) << ',' << solution2(bst2.root) << endl;

    return 0;
}