#include "Queue.h"

int Queue::getFront() {
    if (size == 0) {
        cout<<"Not enough elements"<<endl;
        return -1;
    }
    return arr[0];
}

void Queue::enqueue(int val) {
    arr.push_back(val);
    size++;
}

int Queue::dequeue() {
    if (size == 0) {
        cout<<"Not enough elements"<<endl;
        return -1;
    }
    int val = getFront();
    arr.erase(arr.begin(), arr.begin()+1);
    size--;
    return val;
}

void Queue::print() {
    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}