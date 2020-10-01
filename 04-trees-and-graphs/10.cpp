// Check if one tree is a subtree of another

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

string traverse(Node* root) {
    if(!root) return "*";
    
    string str = "";
    str += to_string(root->val);
    str += traverse(root->left);
    str += traverse(root->right);

    return str;
}

bool match(Node* p, Node* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;

    return match(p->left, q->left) && match(p->right, q->right);
}

bool solution1(Node* p, Node* q) {
    // compare pre-order traversals
    string pstr = traverse(p);
    string qstr = traverse(q);

    return pstr.find(qstr) != string::npos;

}

bool solution2(Node* p, Node* q) {
    // match trees if roots have same value
    if(!q) return true;
    if(!p) return false;
    if(p->val == q->val && match(p, q)) return true;

    return solution2(p->left, q) || solution2(p->right, q);
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
    bst2.insert(2);
    bst2.insert(1);
    bst2.insert(3);

    BinarySearchTree bst3;
    bst3.insert(2);
    bst3.insert(1);
    bst3.insert(4);

    cout << solution1(bst1.root, bst2.root) << ',' << solution2(bst1.root, bst2.root) << endl;
    cout << solution1(bst1.root, bst3.root) << ',' << solution2(bst1.root, bst3.root) << endl;
 

    return 0;
}