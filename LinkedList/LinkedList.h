using namespace std;
#include <iostream>

template <class T>
class LinkedList {
    private:
        struct Node {
            T val;
            Node* next;
            Node(T _val):val(_val){};
        };
        Node* headPointer;
        Node* tailPointer;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        T getValAtI(int index);
        int getSize();
        void push_back(T val);
        T removeAtIndex(int index);
        T removeByVal(T val);
        void swap(int index1, int index2);
        void print();
          
};