#include "AVL.h"

template <class T>
AVL<T>::~AVL() {
    // delete root;
}

template <class T>
void AVL<T>::insert(Node* &node, T val) {
    if (node == NULL) {
        node = new Node(val);
    } else {
        if (node->val < val) {
            insert(node->right, val);
        } else {
            insert(node->left, val);
        }
    }
    balanceTree(node);
}

template <class T>
void AVL<T>::insert(T val) {
    insert(root, val);
}

template <class T>
int AVL<T>::height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    // if (node->left == NULL && node->right == NULL) {
    //     return 0;
    // }
    return node->height;
}

template <class T>
void AVL<T>::updateHeight(Node* &node) {
    if (node->left == NULL && node->right == NULL) {
        node->height = 0;
    } else if (node->left == NULL) {
        node->height = 1+height(node->right);
    } else if (node->right == NULL) {
        node->height = 1+height(node->left);
    } else {
        node->height = 1+max(height(node->left), height(node->right));
    }
}

template <class T>
void AVL<T>::rotateRight(Node* &node) {
    Node* temp1 = node;
    Node* temp2 = node->left->right;
    node = node->left;
    node->right = temp1;
    node->right->left = temp2;

    updateHeight(node->right);
    updateHeight(node);
    // delete temp1;
    // delete temp2;
}

template <class T>
void AVL<T>::rotateLeft(Node* &node) {
    Node* temp1 = node;
    Node* temp2 = node->right->left;
    node = node->right;
    node->left = temp1;
    node->left->right = temp2;
    
    updateHeight(node);
    // delete temp1;
    // delete temp2;
}

template <class T>
void AVL<T>::rotateLR(Node* &node) {
    rotateLeft(node->left);
    rotateRight(node);
}

template <class T>
void AVL<T>::rotateRL(Node* &node) {
    rotateRight(node->right);
    rotateLeft(node);
}

template <class T>
int AVL<T>::calculateBalance(Node* node) {
    if (node->left == NULL && node->right == NULL) {
        return 0;
    } else if (node->left == NULL) {
        return -1-height(node->right);
    } else if (node->right == NULL) {
        return 1+height(node->left);
    } else {
        return height(node->left)-height(node->right);
    }
}

template <class T>
void AVL<T>::balanceTree(Node* &node) {
    if (node == NULL) {
        return;
    }
    Node* leftChild = node->left;
    Node* rightChild = node->right;
    int balance = calculateBalance(node);
    if (leftChild != NULL) {
        int leftBalance = calculateBalance(leftChild);
        if (balance > 1) {
            if (leftBalance > 0) {
                rotateRight(node);
            } else {
                rotateLR(node);
            }
        }
    }
    if (rightChild != NULL) {
        int rightBalance = calculateBalance(rightChild);
        if (balance < -1) {
            if (rightBalance < 0) {
                rotateLeft(node);
            } else {
                rotateRL(node);
            }
        }
    }
    updateHeight(node);
    // delete leftChild;
    // delete rightChild;
}

template <class T>
void AVL<T>::printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    cout<<node->val<<" ";
    printInOrder(node->right);
}

template <class T>
void AVL<T>::printInOrder() {
    printInOrder(root);
    cout<<endl;
}

template <class T>
void AVL<T>::printPreOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    cout<<node->val<<" ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template <class T>
void AVL<T>::printPreOrder() {
    printPreOrder(root);
    cout<<endl;
}

template <class T>
void AVL<T>::printPostOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout<<node->val<<" ";
}

template <class T>
void AVL<T>::printPostOrder() {
    printPostOrder(root);
    cout<<endl;
}

template <class T>
void AVL<T>::remove(Node* &node, T val) {
    if (node == NULL) {
        return;
    }
    if (node->val == val) {
        if (node->left == NULL && node->right == NULL) {
            node = NULL;
        } else if (node->left == NULL) {
            Node* temp = node;
            node = node->right;
            //delete temp;
        } else if (node->right == NULL) {
            Node* temp = node;
            node = node->left;
            node->left = NULL;
            //delete temp;
        } else {
            Node* temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            node->val = temp->val;
            temp->val = val;
            remove(node->right, temp->val);
            //delete temp;
        }
        balanceTree(node);
        return;
    }
    if (node->val > val) {
        remove(node->left, val);
    } else {
        remove(node->right, val);
    }
    balanceTree(node);
}

template <class T>
T AVL<T>::remove(T val) {
    remove(root, val);
    return val;
}

template <class T>
bool AVL<T>::search(Node* node, T val) {
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
bool AVL<T>::search(T val) {
    return search(root, val);
}

template <class T>
void AVL<T>::swap(T node1, T node2) {
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

    // delete parentNode1;
    // delete node1Pointer;
    // delete parentNode2;
    // delete node2Pointer;
    // delete temp1;
    // delete temp2;
}