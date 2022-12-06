#include "LinkedList/LinkedList.cpp"

int main() {
    LinkedList lst = LinkedList();
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.print();
    cout<<lst.removeByVal(1)<<endl;
    cout<<lst.getValAtI(1)<<endl;
    lst.print();
    return 0;
}