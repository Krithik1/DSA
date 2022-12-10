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
        T getFront();
        void enqueue(T val);
        T dequeue();
        bool isEmpty();
        void print();
};