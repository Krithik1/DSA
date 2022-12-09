#include "DisjointSet.h"

template <class T>
DisjointSet<T>::DisjointSet(int _size) {
    size = _size;
    set = vector<int>(size, -1);
}

template <class T>
bool DisjointSet<T>::find(T x, T y) {
    return (set[x] == set[y] && set[x] != -1);
}

template <class T>
void DisjointSet<T>::merge(T x, T y) {
    if (find(x, y)) {
        cout<<"We have a cycle"<<endl;
        return;
    }
    if (set[x] < 0 && set[y] < 0) {
        if (set[y] < set[x]) {
            set[y]+=set[x];
            set[x] = y;
        } else {
            set[x]+=set[y];
            set[y] = x;
        }
    } else if (set[x] < 0) {
        merge(x, set[y]);
    } else if (set[y] < 0) {
        merge(set[x], y);
    } else {
        merge(set[x], set[y]);
    }
}

template <class T>
void DisjointSet<T>::print() {
    for (T val : set) {
        cout<<val<<" ";
    }
    cout<<endl;
}