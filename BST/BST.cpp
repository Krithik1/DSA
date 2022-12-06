#include "BST.h"

template <class T>
BST<T>::BST(vector<T> arr) {
    root = NULL;
    for (T val : arr) {
        insert(val);
    }
}

template <class T>
BST<T>::~BST() {
    root = NULL;
    delete root;
}

template <class T>
void BST<T>::insert(Node* &node, T val) {
    if (node == NULL) {
        node = new Node(val);
        // cout<<node->val<<endl;
        // cout<<root->val<<endl;
        // if (root->right != NULL) {
        //     cout<<root->right->val<<endl;
        // }
        // if (root->left != NULL) {
        //     cout<<root->left->val<<endl;
        // }
        // if (root->right->right != NULL) {
        //     cout<<root->right->right->val<<endl;
        // }
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
void BST<T>::swap(Node* parent1, Node* val1, bool isLeft1, Node* parent2, Node* val2, bool isLeft2) {
    if (parent1 != NULL) {
        if (isLeft1) {
            parent1->left = val2;
        } else {
            parent1->right = val2;
        }
    } else {
        root = val2;
    }
    if (parent2 != NULL) {
        if (isLeft2) {
            parent2->left = val1;
        } else {
            parent2->right = val1;
        }
    } else {
        root = val1;
    }
    Node* temp1 = val1->left;
    Node* temp2 = val1->right;
    val1->left = val2->left;
    val2->left = temp1;
    val1->right = val2->right;
    val2->right = temp2;

    temp1 = NULL;
    delete temp1;
    temp2 = NULL;
    delete temp2;
}

template <class T>
void BST<T>::remove(Node* parent, Node* &node, T val, bool isLeft) {
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
            node->right = NULL;
            temp = NULL;
            delete temp;
        } else if (node->right == NULL) {
            Node* temp = node;
            node = node->left;
            node->left = NULL;
            temp = NULL;
            delete temp;
        } else {
            Node* parentTemp = node;
            Node* temp = node->right;
            while (temp != NULL) {
                parentTemp = temp;
                temp = node->left;
            }
            swap(parent, node, isLeft, parentTemp, temp, 1);
            temp = NULL;
            delete temp;
            parentTemp = NULL;
            delete parentTemp;
        }
    }
    if (node->val > val) {
        remove(node, node->left, val, 1);
    } else {
        remove(node, node->right, val, 0);
    }
}

template <class T>
T BST<T>::remove(T val) {
    remove(NULL, root, val, 0);
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