using namespace std;
#include <iostream>
#include <vector>

template <class T>
class Heap {
    private:
        int size;
        vector<T> arr;
        void heapifyUp(int index);
        void heapifyDown(vector<int> &arr, int index);
    public:
        Heap():size(0){};
        void push(T val);
        T pop();
        bool isEmpty();
        void print();
};