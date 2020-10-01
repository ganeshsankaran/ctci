#include "LinkedList.h"

using namespace std;

Node::Node(int val) {
    this->val = val;
    this->next = NULL;
}

LinkedList::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
}

LinkedList::~LinkedList() {
    Node *curr = this->head, *next = NULL;
    
    while(curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void LinkedList::push_front(int val) {
    if(!this->head) {
        this->head = new Node(val);
        this->tail = this->head;
    }
    else {
        Node* curr = new Node(val);
        curr->next = this->head;
        this->head = curr;
    }
}

void LinkedList::append(LinkedList& l) {
    this->tail->next = l.head;
    this->tail = l.tail;
}

void LinkedList::push_back(int val) {
    if(!this->head) {
        this->head = new Node(val);
        this->tail = this->head;
    }
    else {
        Node* curr = new Node(val);
        this->tail->next = curr;
        this->tail = curr;
    }
}

int LinkedList::size() {
    Node* curr = this->head;
    int n = 0;
    
    while(curr) {
        curr = curr->next;
        n++;
    }

    return n;
}

ostream& operator<<(ostream& os, LinkedList& l) {
    for(Node* p = l.head; p != NULL; p = p->next) {
        os << p->val;
        if(p->next) os << " -> ";
    }
    return os;
}