#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue {
    private:
        vector<T> arr;
        int size;
    public:
        Queue():size(0){};
        T getFront(); //O(1)
        void enqueue(T val); //O(1)
        T dequeue(); //O(1)
        bool isEmpty(); //O(1)
        void print(); //O(n)
};