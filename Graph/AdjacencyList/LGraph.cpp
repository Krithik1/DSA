#include "LGraph.h"
#include <queue>
#include <stack>

void LGraph::insertNode() {
    adjacencyList.push_back(vector<int>());
    numNodes++;
}

void LGraph::insertEdge(int node1, int node2) {
    adjacencyList[node1].push_back(node2);
    adjacencyList[node2].push_back(node1);
}

void LGraph::bfs(int startNode) {
    vector<bool> visited = vector<bool>(numNodes, false);
    queue<int> q = queue<int>();
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty()) {
        int node = q.front();
        cout<<node<<endl;
        q.pop();
        for (int i = 0; i < adjacencyList[node].size(); i++) {
            int nodeOfInterest = adjacencyList[node][i];
            if (!visited[nodeOfInterest]) {
                visited[nodeOfInterest] = true;
                q.push(nodeOfInterest);
            }
        }
    }
}

void LGraph::dfs(int startNode) {
    vector<bool> visited = vector<bool>(numNodes, false);
    stack<int> s = stack<int>();
    s.push(startNode);
    visited[startNode] = true;
    while (!s.empty()) {
        int node = s.top();
        cout<<node<<endl;
        s.pop();
        for (int i = adjacencyList[node].size()-1; i >= 0; i--) {
            int nodeOfInterest = adjacencyList[node][i];
            if (!visited[nodeOfInterest]) {
                visited[nodeOfInterest] = true;
                s.push(nodeOfInterest);
            }
        }
    }
}

void LGraph::printAdjacencyList() {
    for (vector<int> v : adjacencyList) {
        for (int i : v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}