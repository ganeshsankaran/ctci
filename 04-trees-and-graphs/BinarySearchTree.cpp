#include "BinarySearchTree.h"

Node::Node(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
}

Node::~Node() {
    delete this->left;
    delete this->right;
}

BinarySearchTree::BinarySearchTree() {
    this->root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete this->root;
}

void BinarySearchTree::insert(int val) {
    if(!this->root) this->root = new Node(val);
    else insert(val, this->root);
}

void BinarySearchTree::insert(int val, Node* root) {
    if(val < root->val) {
        if(root->left) insert(val, root->left);
        else root->left = new Node(val);
    }
    else if(val > root->val) {
        if(root->right) insert(val, root->right);
        else root->right = new Node(val);
    }
}

ostream& operator<<(ostream& os, Node* node) {
    if(node) {
        os << node->left;
        os << node->val << ' ';
        os << node->right;
    }

    return os;
}

ostream& operator<<(ostream& os, BinarySearchTree& bst) {
    os << bst.root;

    return os;
}
