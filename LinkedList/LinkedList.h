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
        T getValAtI(int index); //O(n)
        int getSize(); //O(1)
        void push_back(T val); //O(1) - because of tail pointer else O(n)
        T removeAtIndex(int index); //O(n)
        T removeByVal(T val); //O(n)
        void swap(int index1, int index2); //O(n)
        void print(); //O(n)
          
};