#include "BST.h"

template <class T>
BST<T>::~BST() {
    clear(root);
}

template <class T>
void BST<T>::clear(Node* &node) {
    if (node == NULL) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
    node = NULL;
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
    Node* parentNode1 = NULL;
    Node* node1Pointer = root;
    Node* parentNode2 = NULL;
    Node* node2Pointer = root;
    bool isLeft1 = false;
    bool isLeft2 = false;
    while (node1Pointer->val != node1) {
        parentNode1 = node1Pointer;
        if (node1 < node1Pointer->val) {
            if (node1Pointer->left == NULL) {
                return;
            }
            isLeft1 = true;
            node1Pointer = node1Pointer->left;
        } else {
            if (node1Pointer->right == NULL) {
                return;
            }
            isLeft1 = false;
            node1Pointer = node1Pointer->right;
        }
    }
    while (node2Pointer->val != node2) {
        parentNode2 = node2Pointer;
        if (node2 < node2Pointer->val) {
            if (node2Pointer->left == NULL) {
                return;
            }
            isLeft1 = true;
            node2Pointer = node2Pointer->left;
        } else {
            if (node2Pointer->right == NULL) {
                return;
            }
            isLeft1 = false;
            node2Pointer = node2Pointer->right;
        }
    }
    Node* temp1 = node1Pointer->left;
    Node* temp2 = node1Pointer->right;
    if (isLeft1 && isLeft2) {
        parentNode1->left = node2Pointer;
        parentNode2->left = node1Pointer;
    } else if (isLeft1) {
        parentNode1->left = node2Pointer;
        parentNode2->right = node1Pointer;
    } else if (isLeft2) {
        parentNode1->right = node2Pointer;
        parentNode2->left = node1Pointer;
    } else {
        parentNode1->right = node2Pointer;
        parentNode2->right = node1Pointer;
    }
    node1Pointer->left = node2Pointer->left;
    node1Pointer->right = node2Pointer->right;
    node2Pointer->left = temp1;
    node2Pointer->right = temp2;
}

template <class T>
void BST<T>::remove(Node* &node, T val) {
    if (node == NULL) {
        return;
    }
    if (node->val == val) {
        if (node->left == NULL && node->right == NULL) {
            node = NULL;
        } else if (node->left == NULL) {
            Node* temp = node;
            node = node->right;
        } else if (node->right == NULL) {
            Node* temp = node;
            node = node->left;
            node->left = NULL;
        } else {
            Node* temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            node->val = temp->val;
            temp->val = val;
            remove(node->right, temp->val);
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
bool BST<T>::search(Node* node, T val) {
    if (node == NULL) {
        return false;
    }
    if (node->val == val) {
        return true;
    }
    if (node->val < val) {
        return search(node->right, val);
    }
    return search(node->left, val);
}

template <class T>
bool BST<T>::search(T val) {
    return search(root, val);
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