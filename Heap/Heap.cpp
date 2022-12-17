#include "Heap.h"

template <class T>
Heap<T>::Heap(vector<T> _arr) {
    arr = _arr;
    size = arr.size();
    int startIndex = arr.size()/2-1;
    for (int i = startIndex; i >= 0; i--) {
        heapifyDown(arr, i);
    }
}

template <class T>
void Heap<T>::heapifyUp(int curr) {
    int index = curr/2-1;
    curr--;
    if (index < 0) {
        return;
    }
    if (arr[index] < arr[curr]) {
        int temp = arr[index];
        arr[index] = arr[curr];
        arr[curr] = temp;
        curr = index;
        heapifyUp(curr+1);
    }
}

template <class T>
void Heap<T>::heapifyDown(vector<int> &arr, int curr) {
    if (curr > size) {
        return;
    }
    int leftIndex = 2*curr+1;
    int rightIndex = 2*curr+2;
    int largest = leftIndex;
    if (leftIndex >= size) {
        return;
    } else if (rightIndex >= size) {
        largest = leftIndex;
    } else {
        if (arr[leftIndex] < arr[rightIndex]) {
            largest = rightIndex;
        }
    }
    if (arr[largest] > arr[curr]) {
        int temp = arr[largest];
        arr[largest] = arr[curr];
        arr[curr] = temp;
        heapifyDown(arr, largest);
    }
}

template <class T>
void Heap<T>::push(T val) {
    arr.push_back(val);
    size++;
    heapifyUp(size);
}

template <class T>
T Heap<T>::pop() {
    if (size == 0) {
        cout<<"Not enough elements"<<endl;
        return T();
    }
    T temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;
    arr.pop_back();
    size--;
    heapifyDown(arr, 0);
    return temp;
}

template <class T>
bool Heap<T>::isEmpty() {
    return (size == 0);
}

template <class T>
void Heap<T>::print() {
    for (T val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;
}