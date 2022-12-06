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
        void swap(Node* parent1, Node* val1, bool isLeft1, Node* parent2, Node* val2, bool isLeft2);
        void remove(Node* parent, Node* &node, T val, bool isLeft);
        void printInOrder(Node* node);
        void printPreOrder(Node* node);
        void printPostOrder(Node* node);
    public:
        BST():root(NULL){};
        ~BST();
        BST(vector<T> arr);
        void insert(T val);
        T remove(T val);
        void build(vector<T> arr);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
};