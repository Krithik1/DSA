#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BST/BST.cpp"
#include "AVL/AVL.cpp"

int main() {
    AVL<int> avl = AVL<int>();
    avl.insert(9);
    avl.insert(6);
    avl.insert(5);
    avl.insert(4);
    avl.insert(3);
    avl.insert(2);
    avl.remove(5);
    avl.remove(6);
    avl.insert(1);
    avl.swap(3,9);
    avl.printInOrder();
    avl.printPreOrder();
    avl.printPostOrder();
    return 0;
}