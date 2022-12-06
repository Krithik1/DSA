#include "Stack.h"

Stack::Stack() {
    topIndex = -1;
}

int Stack::getTop() {
    if (topIndex == -1) {
        cout<<"Not enough elements"<<endl;
        return -1;
    }
    return arr[topIndex];
}

void Stack::push(int val) {
    arr.push_back(val);
    topIndex++;
}

int Stack::pop() {
    int element = arr[topIndex];
    arr.pop_back();
    topIndex--;
    return element;
}

void Stack::print() {
    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}