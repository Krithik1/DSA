#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    headPointer = NULL;
    tailPointer = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    delete headPointer;
    headPointer = NULL;
    delete tailPointer;
    tailPointer = NULL;
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
T LinkedList<T>::getValAtI(int index) {
    if (index >= size) {
        return T();
    }
    Node* root = headPointer;
    for (int i = 0; i < index; i++) {
        root = root->next;
    }
    int val = root->val;
    return val;
}

template <class T>
void LinkedList<T>::push_back(T val) {
    Node* newNode = new Node(val);
    if (headPointer == NULL && tailPointer == NULL) {
        headPointer = newNode;
        tailPointer = newNode;
        size++;
        return;
    }
    Node* tailNode = tailPointer;
    tailNode->next = newNode;
    tailPointer = newNode;
    size++;
}

template <class T>
T LinkedList<T>::removeAtIndex(int index) {
    if (index >= size) {
        return T();
    }
    Node* rootNode = headPointer;
    Node* prevNode = NULL;
    Node* nextNode = rootNode->next;
    for (int i = 0; i < index; i++) {
        prevNode = rootNode;
        rootNode = rootNode->next;
        nextNode = rootNode->next;
    }
    if (prevNode == NULL) {
        headPointer = nextNode;
    } else if (nextNode == NULL) {
        tailPointer = prevNode;
    } else {
        prevNode->next = nextNode;
    }
    size--;
    T val = rootNode->val;
    return val;
}

template <class T>
T LinkedList<T>::removeByVal(T val) {
    Node* rootNode = headPointer;
    Node* prevNode = NULL;
    Node* nextNode = rootNode->next;
    
    for (int index = 0; index < size; index++) {
        if (rootNode->val == val) {
            if (prevNode == NULL) {
                headPointer = nextNode;
            } else if (nextNode == NULL) {
                tailPointer = prevNode;
            } else {
                prevNode->next = nextNode;
            }
            size--;
            rootNode = NULL;
            delete rootNode;
            prevNode = NULL;
            delete prevNode;
            nextNode = NULL;
            delete nextNode;
            return val;
        }
        prevNode = rootNode;
        rootNode = rootNode->next;
        if (rootNode != NULL) {
            nextNode = rootNode->next;
        }
    }
    cout<<"Element not in the list"<<endl;
    return T();
}

template <class T>
void LinkedList<T>::swap(int index1, int index2) {
    Node* prevIndex1 = NULL;
    Node* headIndex1 = headPointer;
    Node* prevIndex2 = NULL;
    Node* headIndex2 = headPointer;
    int index = 0;
    while (index != index1 && headIndex1 != NULL) {
        prevIndex1 = headIndex1;
        headIndex1 = headIndex1->next;
        index++;
    }
    index = 0;
    while (index != index2 && headIndex2 != NULL) {
        prevIndex2 = headIndex2;
        headIndex2 = headIndex2->next;
        index++;
    }
    if (headIndex1 == NULL || headIndex2 == NULL) {
        return;
    }
    if (prevIndex1 != NULL) {
        prevIndex1->next = headIndex2;
    } else {
        headPointer = headIndex2;
    }
    if (prevIndex2 != NULL) {
        prevIndex2->next = headIndex1;
    } else {
        headPointer = headIndex1;
    }
    Node* temp = headIndex1->next;
    headIndex1->next = headIndex2->next;
    headIndex2->next = temp;
    temp = NULL;
}

template <class T>
void LinkedList<T>::print() {
    int size_ = size;
    if (size_ == 0) {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* rootNode = headPointer;
    while (size_ > 0) {
        cout<<rootNode->val<<" ";
        rootNode = rootNode->next;
        size_--;
    }
    cout<<endl;
}