#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack {
    vector<T> arr;
    int topIndex;
    int size;
    public:
        Stack();
        T getTop(); //O(1)
        void push(T val); //O(1)
        T pop(); //O(1)
        bool isEmpty(); //O(1)
        void print(); //O(n)
};