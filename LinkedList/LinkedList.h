using namespace std;
#include <iostream>

class LinkedList {
    private:
        class Node {
          public:
            int val;
            Node* next;
            Node(int _val):val(_val){};
          };
        Node* headPointer;
        Node* tailPointer;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        int getValAtI(int index);
        int getSize();
        void push_back(int val);
        int removeAtIndex(int index);
        int removeByVal(int val);
        void print();
          
};