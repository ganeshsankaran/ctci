#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    Node(int id);

    int id;
    int indegree;
    vector<Node*> children;
};

class Graph {
public:
    ~Graph();
    
    void insert_node(int id);
    void insert_edge(int ida, int idb);
    
    unordered_map<int, Node*> nodes;
};