#include <iostream>
#include <vector>
using namespace std;

class Queue {
    private:
        vector<int> arr;
        int size;
    public:
        Queue():size(0){};
        int getFront();
        void enqueue(int val);
        int dequeue();
        void print();
};