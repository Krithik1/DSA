using namespace std;
#include <iostream>
#include <vector>

template <class T>
class DisjointSet {
    private:
        vector<T> set;
        int size;
    public:
        DisjointSet(int size_);
        void merge(T x, T y);
        bool find(T x, T y);
        void print();
};