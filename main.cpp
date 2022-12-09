#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BST/BST.cpp"
#include "AVL/AVL.cpp"
#include "Heap/Heap.cpp"

int main() {
    Heap<int> heap = Heap<int>();
    heap.push(3);
    heap.print();
    heap.push(4);
    heap.print();
    heap.push(1);
    heap.print();
    heap.push(50);
    heap.print();
    heap.push(45);
    heap.print();
    heap.push(100);
    heap.print();
    heap.push(46);
    heap.print();
    heap.pop();
    heap.print();
    return 0;
}