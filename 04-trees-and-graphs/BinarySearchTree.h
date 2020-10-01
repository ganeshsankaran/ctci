#include <iostream>

using namespace std;

class Node {
public:
    Node(int val);
    ~Node();

    int val;
    Node* left;
    Node* right;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int val);
    void insert(int val, Node* root);
    Node* root;
};

ostream& operator<<(ostream& os, Node* node);
ostream& operator<<(ostream& os, BinarySearchTree& bst);