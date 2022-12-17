using namespace std;
#include <iostream>
#include <vector>

template <class T>
class Heap {
    private:
        int size;
        vector<T> arr;
        void heapifyUp(int index); //O(log(n)) - check parent if greater than parent then swap else break
        void heapifyDown(vector<int> &arr, int index); //O(log(n)) - check children if less than max of children swap else break
    public:
        Heap():size(0){}; //O(1)
        Heap(vector<T> _arr); //O(n) - take non-leaf nodes and heapify down
        void push(T val); //O(log(n)) - push at end and heapify up
        T pop(); //O(log(n)) - swap with last element, delete last element and heapify down first element
        bool isEmpty(); //O(1) - check size
        void print(); //O(n) - print every element in arr
};