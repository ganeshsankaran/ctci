#include <iostream>

using namespace std;

struct Node {
    Node(int val);

    int val;
    Node* next;
};

struct LinkedList {
    LinkedList();
    ~LinkedList();

    void append(LinkedList& l);
    void push_front(int val);
    void push_back(int val);
    int size();

    Node* head;
    Node* tail;
};

ostream& operator<<(ostream& os, LinkedList& l);