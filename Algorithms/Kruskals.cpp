using namespace std;
#include <iostream>
#include <vector>
#include "../DisjointSet/DisjointSet.cpp"
#include "../Graph/AdjacencyList/LGraph.cpp"

// Sorted array Implementation

// void insertElement(vector<int> &arr, int val) {
//   int low = 0;
//   int high = arr.size()-1;
//   int pos = (high+low)/2;
//   cout<<"low: "<<low<<endl;
//   cout<<"high: "<<high<<endl;
//   while (pos >= low && pos <= high) {
//     if (val > arr[pos]) {
//       low = pos+1;
//     } else {
//       high = pos-1;
//     }
//     cout<<"low: "<<low<<endl;
//     cout<<"high: "<<high<<endl;
//     pos = (high+low)/2;
//   }
//   arr.insert(arr.begin()+pos+1, val);
// }

void kruskalsAlgo(vector<pair<int,int>> edgeList, int numNodes) {
  LGraph g = LGraph(numNodes);
  DisjointSet ds = DisjointSet(numNodes);
  int numEdge = 0;
  while (edgeList.size() > 0) {
    if (numEdge == numNodes-1) {
      break;
    }
    pair<int,int> edge = edgeList[0];
    edgeList.erase(edgeList.begin());
    if (ds.find(edge.first) != ds.find(edge.second)) {
      ds.merge(edge.first, edge.second);
      g.insertEdge(edge.first, edge.second);
      numEdge++;
    }
  }
  g.printAdjacencyList();
  ds.print();
}