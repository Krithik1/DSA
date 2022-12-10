#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BST/BST.cpp"
#include "AVL/AVL.cpp"
#include "Heap/Heap.cpp"
#include "DisjointSet/DisjointSet.cpp"
#include "Graph/AdjencyMatrix/MGraph.cpp"
#include "Graph/AdjencyList/LGraph.cpp"

int main() {
    // Graph g = Graph(7);
    // g.insertEdge(0, 1);
    // g.insertEdge(0, 2);
    // g.insertEdge(0, 6);
    // g.insertEdge(1, 2);
    // g.insertEdge(1, 5);
    // g.insertEdge(2, 3);
    // g.insertEdge(2, 5);
    // g.insertEdge(2, 4);
    // g.insertEdge(5, 4);
    // g.insertEdge(3, 4);
    // g.insertEdge(3, 6);
    MGraph g = MGraph(5);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(1, 4);
    g.dfs(0);
    return 0;
}