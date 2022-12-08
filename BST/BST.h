using namespace std;
#include <iostream>
#include <vector>

template <class T>
class BST {
    private:
        struct Node {
            T val;
            Node* left;
            Node* right;
            Node(T _val):val(_val){};
        };
        Node* root;
        void insert(Node* &node, T val);
        void swap(T node1, T node2);
        void remove(Node* &node, T val);
        void printInOrder(Node* node);
        void printPreOrder(Node* node);
        void printPostOrder(Node* node);
    public:
        BST():root(NULL){};
        ~BST();
        void insert(T val);
        T remove(T val);
        void build(vector<T> arr);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
};