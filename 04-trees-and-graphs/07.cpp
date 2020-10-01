// topological sort a project by dependencies

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include "Graph.h"

using namespace std;

vector<int> solution(Graph& G) {
    // topological sort using DFS (assuming DAG)
    // O(V + E)
    vector<int> order;
    queue<Node*> q;

    for(unordered_map<int, Node*>::iterator it = G.nodes.begin(); it != G.nodes.end(); it++) {
        if(it->second->indegree == 0) q.push(it->second);
    }

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        order.push_back(node->id);

        for(Node* child : node->children) {
            child->indegree--;
            if(child->indegree == 0) {
                q.push(child);
            }
        }
    }

    return order;

}

int main() {
    Graph G;
    G.insert_node(1);
    G.insert_node(2);
    G.insert_node(3);
    G.insert_node(4);
    G.insert_node(5);
    G.insert_node(6);
    G.insert_node(7);
    G.insert_edge(6, 1);
    G.insert_edge(6, 2);
    G.insert_edge(6, 3);
    G.insert_edge(2, 1);
    G.insert_edge(2, 5);
    G.insert_edge(3, 1);
    G.insert_edge(1, 5);
    G.insert_edge(4, 7);

    vector<int> order = solution(G);
    for(int id : order) {
        cout << id << ' ';
    }
    cout << endl;

    return 0;
}