#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BST/BST.cpp"
#include "AVL/AVL.cpp"
#include "Heap/Heap.cpp"
#include "DisjointSet/DisjointSet.cpp"

int main() {
    DisjointSet<int> set = DisjointSet<int>(10);
    set.merge(3,1);
    set.merge(9,6);
    set.merge(8,0);
    set.merge(5,9);
    set.merge(2,3);
    set.print();
    return 0;
}