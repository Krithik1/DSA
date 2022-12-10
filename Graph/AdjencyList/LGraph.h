using namespace std;
#include <vector>

class LGraph {
    private:
        int numNodes;
        vector<vector<int>> adjencyList;
    public:
        LGraph(int n):numNodes(n),adjencyList(vector<vector<int>>(n, vector<int>())){};
        void insertNode();
        void insertEdge(int node1, int node2);
        void bfs(int startNode);
        void dfs(int startNode);
        void printAdjencyList();
};