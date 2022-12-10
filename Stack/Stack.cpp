#include "Stack.h"

template <class T>
Stack<T>::Stack() {
    topIndex = -1;
    size = 0;
}

template <class T>
T Stack<T>::getTop() {
    if (topIndex == -1) {
        cout<<"Not enough elements"<<endl;
        return T();
    }
    return arr[topIndex];
}

template <class T>
void Stack<T>::push(T val) {
    arr.push_back(val);
    topIndex++;
    size++;
}

template <class T>
T Stack<T>::pop() {
    T element = arr[topIndex];
    arr.pop_back();
    topIndex--;
    size--;
    return element;
}

template <class T>
bool Stack<T>::isEmpty() {
    return (size == 0);
}

template <class T>
void Stack<T>::print() {
    for (T i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}