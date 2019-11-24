#ifndef TREE_H
#define TREE_H

#include "node.h"

template<class T>
class Tree {
private:
    Node<T>* root;
public:
    int depth;
    QWidget* widget;

    Tree(QWidget* qWidget);
    Node<T>* getRoot();
    Node<T>* rightRotate(Node<T>* node_y);
    Node<T>* leftRotate(Node<T>* node_x);
    int getBalance(Node<T>* node);
    int height(Node<T>* node);
    void insert(T key);
    Node<T>* insertUtil(Node<T>* node, T key);
    Node<T>* minValueNode(Node<T>* node);
    void deleteNode(T key);
    Node<T>* deleteUtil(Node<T>* root, T key);
    void print2D();
    void print2DUtil(Node<T>* node, int space);
    void calculatePos();
    void calculatePosUtil(Node<T>* node, int height);
    void calculateDepth();
    int calculateDepthUtil(Node<T>* node);
};
#endif // TREE_H
