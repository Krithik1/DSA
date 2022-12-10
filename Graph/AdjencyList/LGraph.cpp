#include "LGraph.h"
#include <queue>
#include <stack>

void LGraph::insertNode() {
    adjencyList.push_back(vector<int>());
    numNodes++;
}

void LGraph::insertEdge(int node1, int node2) {
    adjencyList[node1].push_back(node2);
    adjencyList[node2].push_back(node1);
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
        for (int i = 0; i < adjencyList[node].size(); i++) {
            int nodeOfInterest = adjencyList[node][i];
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
        for (int i = adjencyList[node].size()-1; i >= 0; i--) {
            int nodeOfInterest = adjencyList[node][i];
            if (!visited[nodeOfInterest]) {
                visited[nodeOfInterest] = true;
                s.push(nodeOfInterest);
            }
        }
    }
}

void LGraph::printAdjencyList() {
    for (vector<int> v : adjencyList) {
        for (int i : v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}