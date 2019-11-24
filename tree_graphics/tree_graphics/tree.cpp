#include <iostream>

#include "tree.h"
using namespace std;

template <class T>
Tree<T>::Tree(QWidget* qWidget) : widget(qWidget) {
    root = NULL;
}

template <class T>
Node<T>* Tree<T>::getRoot() {
    return root;
}

template <class T>
Node<T>* Tree<T>::rightRotate(Node<T>* node_y) {
    Node<T>* node_x = node_y->getLeft();
    Node<T>* sub_tree_x = node_x->getRight();
    node_x->setRight(node_y);
    node_y->setLeft(sub_tree_x);
    node_y->height = max(height(node_y->getLeft()), height(node_y->getRight())) + 1;
    node_x->height = max(height(node_x->getLeft()), height(node_x->getRight())) + 1;
    return node_x;
}

template <class T>
Node<T>* Tree<T>::leftRotate(Node<T>* node_x) {
    Node<T>* node_y = node_x->getRight();
    Node<T>* sub_tree_y = node_y->getLeft();
    node_y->setLeft(node_x);
    node_x->setRight(sub_tree_y);
    node_x->height = max(height(node_x->getLeft()), height(node_x->getRight())) + 1;
    node_y->height = max(height(node_y->getLeft()), height(node_y->getRight())) + 1;
    return node_y;
}

template <class T>
int Tree<T>::getBalance(Node<T>* node) {
    if (node == NULL)
        return 0;
    return height(node->getLeft()) - height(node->getRight());
}

template <class T>
int Tree<T>::height(Node<T>* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

template <class T>
void Tree<T>::insert(T key) {
    root = insertUtil(root, key);
    calculatePos();
}

template <class T>
Node<T>* Tree<T>::insertUtil(Node<T>* node, T key) {
    if (node == NULL) {
        Node<T>* new_node = new Node<T>(key, widget);
        return new_node;
    }

    if (key < node->getKey())
        node->setLeft(insertUtil(node->getLeft(), key));
    else if (key > node->getKey())
        node->setRight(insertUtil(node->getRight(), key));
    else
        return node;

    node->height = max(height(node->getLeft()), height(node->getRight())) + 1;
    int balance = getBalance(node);

    // Left Left case
    if (balance > 1 && key < node->getLeft()->getKey())
        return rightRotate(node);

    // Right Right case
    if (balance < -1 && key > node->getRight()->getKey())
        return leftRotate(node);

    // Left Right case
    if (balance > 1 && key > node->getLeft()->getKey()) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    // Right Left case
    if (balance < -1 && key < node->getRight()->getKey()) {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
}

template <class T>
Node<T>* Tree<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;

    while ((*current).getLeft() != NULL)
        current = (*current).getLeft();
    return current;
}

template <class T>
void Tree<T>::deleteNode(T key) {
    root = deleteUtil(root, key);
}

template <class T>
Node<T>* Tree<T>::deleteUtil(Node<T>* node, T key) {
    if (node == NULL)
        return node;
    if (key < node->getKey())
        node->setLeft(deleteUtil(node->getLeft(), key));
    else if (key > node->getKey())
        node->setRight(deleteUtil(node->getRight(), key));

    else {
        if (node->getLeft() == NULL || node->getRight() == NULL) {
            Node<T>* temp = (node->getLeft()) ? node->getLeft() : node->getRight();
            if (temp == NULL) {
                temp = node;
                node = NULL;
            }
            else *node = *temp;
            free(temp);
        }
        else {
            Node<T>* temp = minValueNode(node->getRight());
            node->setKey(temp->getKey());
            node->setRight(deleteUtil(node->getRight(), (temp->getKey())));
        }
    }

    if (node == NULL)
        return node;

    node->height = max(height(node->getLeft()), height(node->getRight())) + 1;
    int balance  = getBalance(node);

    // Left Left case
    if (balance > 1 && key < node->getLeft()->getKey())
        return rightRotate(node);

    // Right Right case
    if (balance < -1 && key > node->getRight()->getKey())
        return leftRotate(node);

    // Left Right case
    if (balance > 1 && key > node->getLeft()->getKey()) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    // Right Left case
    if (balance < -1 && key < node->getRight()->getKey()) {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
}

template <class T>
void Tree<T>::print2D() {
    print2DUtil(root, 0);
}

template <class T>
void Tree<T>::print2DUtil(Node<T>* node, int space) {
    if (node == NULL)
        return;
    space += 10;
    print2DUtil(node->getRight(), space);
    cout << endl;
    int i = 10;
    for (; i < space; ++i)
        cout << " ";
    cout << node->getKey() << endl;
    print2DUtil(node->getLeft(), space);
}

template <class T>
void Tree<T>::calculatePos() {
    calculateDepth();
    root->pos->setX(800.0 / 2.0);
    root->pos->setY(556.0 / (depth + 1) - 22.0);
    calculatePosUtil(root, 1);
}

template <class T>
void Tree<T>::calculatePosUtil(Node<T>* node, int height) {
    if (node != NULL) {
        node->refreshPosChild(height, depth);
        calculatePosUtil(node->getLeft(), height + 1);
        calculatePosUtil(node->getRight(), height + 1);
    }
}

template <class T>
void Tree<T>::calculateDepth() {
    depth = calculateDepthUtil(root);
}

template <class T>
int Tree<T>::calculateDepthUtil(Node<T>* node) {
    if (node == NULL)
        return 0;
    else {
        int lDepth = calculateDepthUtil(node->getLeft());
        int rDepth = calculateDepthUtil(node->getRight());
        if (lDepth > rDepth)
            return lDepth + 1;
        return rDepth + 1;
    }
}
