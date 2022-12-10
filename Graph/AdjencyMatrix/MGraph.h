using namespace std;
#include <vector>

class MGraph {
    private:
        int numNodes;
        vector<vector<int>> matrix;
    public:
        MGraph(int n):numNodes(n),matrix(vector<vector<int>>(n,vector<int>(n, 0))){};
        void insertNode();
        void insertEdge(int node1, int node2);
        void bfs(int startNode);
        void dfs(int startNode);
        void printAdjencyMatrix();
};