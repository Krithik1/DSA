using namespace std;
#include <iostream>

template <class T>
class AVL {
    private:
        struct Node {
            T val;
            int height;
            Node* left;
            Node* right;
            Node(T _val):val(_val){};
        };
        Node* root;
        void insert(Node* &node, T val);
        void remove(Node* &node, T val);
        int height(Node* node);
        int calculateBalance(Node* node);
        void rotateLeft(Node* &node);
        void rotateLR(Node* &node);
        void rotateRight(Node* &node);
        void rotateRL(Node* &node);
        void updateHeight(Node* &node);
        void balanceTree(Node* &node);
        bool search(Node* node, T val);
        void printInOrder(Node* node);
        void printPreOrder(Node* node);
        void printPostOrder(Node* node);
    public:
        AVL():root(NULL){};
        ~AVL();
        void insert(T val);
        T remove(T val);
        bool search(T val);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
};