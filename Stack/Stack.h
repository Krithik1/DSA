#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> arr;
    int topIndex;
    public:
        Stack();
        int getTop();
        void push(int val);
        int pop();
        void print();
};