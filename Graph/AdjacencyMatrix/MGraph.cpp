#include "MGraph.h"
#include <queue>
#include <stack>

void MGraph::insertNode() {
    matrix.push_back(vector<int>(numNodes, 0));
    for (vector<int> v : matrix) {
        v.push_back(0);
    }
    numNodes++;
}

void MGraph::insertEdge(int node1, int node2) {
    matrix[node1][node2] = 1;
    matrix[node2][node1] = 1;
}

void MGraph::bfs(int startNode) {
    vector<bool> visited = vector<bool>(numNodes, false);
    queue<int> q = queue<int>();
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty()) {
        int node = q.front();
        cout<<node<<endl;
        q.pop();
        for (int i = 0; i < numNodes; i++) {
            if (matrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void MGraph::dfs(int startNode) {
    vector<bool> visited = vector<bool>(numNodes, false);
    stack<int> s = stack<int>();
    s.push(startNode);
    visited[startNode] = true;
    while (!s.empty()) {
        int node = s.top();
        cout<<node<<endl;
        s.pop();
        for (int i = numNodes-1; i >= 0; i--) {
            if (matrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}

void MGraph::printAdjacencyMatrix() {
    for (vector<int> v : matrix) {
        for (int i : v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}