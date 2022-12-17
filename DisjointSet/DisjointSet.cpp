#include "DisjointSet.h"


DisjointSet::DisjointSet(int _size) {
    size = _size;
    set = vector<int>(size, -1);
}


int DisjointSet::find(int x) {
    if (set[x] < 0) {
      return x;
    }
    return find(set[x]);
}


void DisjointSet::merge(int x, int y) {
    if (find(x) == find(y)) {
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


void DisjointSet::print() {
    for (int val : set) {
        cout<<val<<" ";
    }
    cout<<endl;
}