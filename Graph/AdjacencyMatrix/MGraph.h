using namespace std;
#include <vector>

class MGraph {
    private:
        int numNodes;
        vector<vector<int>> matrix;
    public:
        MGraph(int n):numNodes(n),matrix(vector<vector<int>>(n,vector<int>(n, 0))){};
        void insertNode(); //O(n)
        void insertEdge(int node1, int node2); //O(1)
        void bfs(int startNode); //O(V^2)
        void dfs(int startNode); //O(V^2)
        void printAdjacencyMatrix();
};