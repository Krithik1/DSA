#include "BST.h"

template <class T>
BST<T>::~BST() {
    root = NULL;
    delete root;
}

template <class T>
void BST<T>::insert(Node* &node, T val) {
    if (node == NULL) {
        node = new Node(val);
        return;
    }
    if (node->val > val) {
        insert(node->left, val);
    } else {
        insert(node->right, val);
    }
}

template <class T>
void BST<T>::insert(T val) {
    insert(root, val);
}

template <class T>
void BST<T>::swap(T node1, T node2) {
    // TODO
}

template <class T>
void BST<T>::remove(Node* &node, T val) {
    if (node == NULL) {
        return;
    }
    if (node->val == val) {
        if (node->left == NULL && node->right == NULL) {
            node = NULL;
            delete node;
        } else if (node->left == NULL) {
            Node* temp = node;
            node = node->right;
            temp = NULL;
            delete temp;
        } else if (node->right == NULL) {
            Node* temp = node;
            node = node->left;
            node->left = NULL;
            temp = NULL;
            delete temp;
        } else {
            Node* temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            node->val = temp->val;
            temp->val = val;
            remove(node->right, temp->val);
            temp = NULL;
            delete temp;
        }
        return;
    }
    if (node->val > val) {
        remove(node->left, val);
    } else {
        remove(node->right, val);
    }
}

template <class T>
T BST<T>::remove(T val) {
    remove(root, val);
    return val;
}

template <class T>
void BST<T>::printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    cout<<node->val<<" ";
    printInOrder(node->right);
}

template <class T>
void BST<T>::printInOrder() {
    printInOrder(root);
    cout<<endl;
}

template <class T>
void BST<T>::printPreOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    cout<<node->val<<" ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template <class T>
void BST<T>::printPreOrder() {
    printPreOrder(root);
    cout<<endl;
}

template <class T>
void BST<T>::printPostOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout<<node->val<<" ";
}

template <class T>
void BST<T>::printPostOrder() {
    printPostOrder(root);
    cout<<endl;
}