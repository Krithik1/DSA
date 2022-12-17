#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BST/BST.cpp"
#include "AVL/AVL.cpp"
#include "Heap/Heap.cpp"
//#include "DisjointSet/DisjointSet.cpp"
#include "Graph/AdjacencyMatrix/MGraph.cpp"
//#include "Graph/AdjencyList/LGraph.cpp"
#include "Algorithms/Kruskals.cpp"
#include "Algorithms/MergeSort.cpp"

int main() {
  // pair<int,int> edge1 = pair<int,int>(0,1);
  // pair<int,int> edge2 = pair<int,int>(0,2);
  // pair<int,int> edge3 = pair<int,int>(1,3);
  // pair<int,int> edge4 = pair<int,int>(1,4);
  // pair<int,int> edge5 = pair<int,int>(2,3);
  // pair<int,int> edge6 = pair<int,int>(3,4);

  // vector<pair<int,int>> edgeList{edge1, edge5, edge4, edge6, edge2, edge3};
  // int numNodes = 5;
  // kruskalsAlgo(edgeList, numNodes);
  vector<int> arr{5, 3, 6, 4, 2, 9, 1};
  mergeSort(arr);
  for (int i : arr) {
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}