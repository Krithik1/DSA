#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BST/BST.cpp"

int main() {
    BST<int> bst = BST<int>();
    bst.insert(4);
    bst.insert(12);
    bst.insert(3);
    bst.insert(5);
    bst.insert(1);
    cout<<bst.remove(3)<<endl;
    cout<<bst.remove(12)<<endl;
    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();
    bst.insert(13);
    bst.insert(50);
    bst.insert(11);
    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();
    cout<<bst.remove(4)<<endl;
    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();
    cout<<bst.remove(5)<<endl;
    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();
    return 0;
}