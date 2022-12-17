using namespace std;
#include <vector>

class LGraph {
    private:
    public:
        int numNodes;
        vector<vector<int>> adjacencyList;
        LGraph(int n):numNodes(n),adjacencyList(vector<vector<int>>(n, vector<int>())){};
        void insertNode(); //O(1)
        void insertEdge(int node1, int node2); //O(1)
        void bfs(int startNode); //O(V+E)
        void dfs(int startNode); //O(V+E)
        void printAdjacencyList();
};