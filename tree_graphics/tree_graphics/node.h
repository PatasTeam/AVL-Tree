#ifndef NODE_H
#define NODE_H

#include <QLabel>
#include <QWidget>
#include <QPointF>

template<class T>
class Node {
private:
    T key;
    Node<T>* left;
    Node<T>* right;
public:
    int height;
    QLabel* label;
    QPointF* pos;
    QLineF* line_left;
    QLineF* line_right;

    Node(T key, QWidget* widget);
    T getKey();
    void setLeft(Node<T>* left);
    void setRight(Node<T>* right);
    Node<T>* getLeft();
    Node<T>* getRight();
    void refreshPosChild(int& height,int& depth);
};

#endif // NODE_H
