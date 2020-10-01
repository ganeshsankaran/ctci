#include "Graph.h"

Node::Node(int id) {
    this->id = id;
    this->indegree = 0;
}

Graph::~Graph() {
    for(unordered_map<int, Node*>::iterator it = this->nodes.begin(); it != this->nodes.end(); it++) {
        delete it->second;
    }
}

void Graph::insert_node(int id) {
    if(this->nodes.find(id) != this->nodes.end()) return;
    
    Node* node = new Node(id);
    this->nodes[id] = node;
}

void Graph::insert_edge(int ida, int idb) {
    Node* a = this->nodes.find(ida)->second;
    Node* b = this->nodes.find(idb)->second;

    a->children.push_back(b);
    b->indegree++;
}