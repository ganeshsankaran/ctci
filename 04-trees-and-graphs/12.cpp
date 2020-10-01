// design an alg to count the number of paths that sum to a given value

#include <iostream>
#include <unordered_map>
#include "BinarySearchTree.h"
using namespace std;

int count_from(Node* root, int target, int curr) {
    if(!root) return 0;

    int count = 0;

    curr += root->val;
    if(curr == target) count++;

    count += count_from(root->left, target, curr);
    count += count_from(root->right, target, curr);
    return count;
}

int solution1(Node* root, int sum) {
    // brute force: count all paths from each node
    // O(n^2) worst, O(n log n) avg
    if(!root) return 0;

    int count = 0;
    
    count += count_from(root, sum, 0);
    count += solution1(root->left, sum);
    count += solution1(root->right, sum);
    return count;
}

int solution2(Node* root, int target, int curr = 0, unordered_map<int, int> sums = unordered_map<int, int>()) {
    // maintain a table of how many times a current sum occurs
    // like finding number of contiguous arrays that sum to target
    // O(n)
    if(!root) return 0;

    curr += root->val;
    int count;
    if(sums.find(curr - target) == sums.end()) count = 0; // find current path count
    else count = sums[curr - target];

    if(curr == target) count++; // path starting from root

    // insert current sum to table
    if(sums.find(curr) == sums.end()) sums[curr] = 1;
    else sums[curr]++;

    count += solution2(root->left, target, curr, sums);
    count += solution2(root->right, target, curr, sums);

    // revert
    sums[curr]--;
    if(sums[curr] == 0) sums.erase(0);

    return count;
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

    cout << solution1(bst1.root, 7) << ',' << solution2(bst1.root, 7) << endl;

    return 0;
}