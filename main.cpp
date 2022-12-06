#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BST/BST.cpp"

int main() {
    vector<int> arr{4,12,3,5,1};
    BST<int> bst = BST<int>(arr);
    cout<<bst.remove(3)<<endl;
    cout<<bst.remove(12)<<endl;
    bst.printInOrder();
    bst.printPreOrder();
    bst.printPostOrder();
    bst.insert(13);
    bst.insert(50);
    return 0;
}