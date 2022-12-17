using namespace std;
#include <iostream>
#include <vector>

class DisjointSet {
    private:
        vector<int> set;
        int size;
    public:
        DisjointSet(int size_);
        void merge(int x, int y);
        int find(int x);
        void print();
};