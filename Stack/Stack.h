#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack {
    vector<T> arr;
    int topIndex;
    public:
        Stack();
        T getTop();
        void push(T val);
        T pop();
        void print();
};