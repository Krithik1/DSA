#include "Queue.h"

template <class T>
T Queue<T>::getFront() {
    if (size == 0) {
        cout<<"Not enough elements"<<endl;
        return T();
    }
    return arr[0];
}

template <class T>
void Queue<T>::enqueue(T val) {
    arr.push_back(val);
    size++;
}

template <class T>
T Queue<T>::dequeue() {
    if (size == 0) {
        cout<<"Not enough elements"<<endl;
        return T();
    }
    T val = getFront();
    arr.erase(arr.begin(), arr.begin()+1);
    size--;
    return val;
}

template <class T>
bool Queue<T>::isEmpty() {
    return (size == 0);
}

template <class T>
void Queue<T>::print() {
    for (T i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}