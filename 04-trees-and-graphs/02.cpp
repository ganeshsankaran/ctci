// given a sorted array with unique integers, write an alg to create a BST with minimal height

#include <iostream>
#include "BinarySearchTree.h"

#define N 7

using namespace std;

Node* solution(int* vals, int start, int end) {
    // recursively insert middle elements of left and right subarrays
    // O(n)
    if(end < start) return NULL;

    int mid = (start + end) / 2;

    Node* curr = new Node(vals[mid]);
    curr->left = solution(vals, start, mid - 1);
    curr->right = solution(vals, mid + 1, end);

    return curr;
}

int main() {
    BinarySearchTree bst;
    int vals[N] = {1, 2, 3, 4, 5, 6, 7};

    bst.root = solution(vals, 0, N - 1);
    cout << bst << endl;
    return 0;
}