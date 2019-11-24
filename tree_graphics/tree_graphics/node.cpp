#include <iostream>
#include <math.h>

#include "node.h"
using namespace std;

template <class T>
Node<T>::Node(T key, QWidget* widget) {
    this->key = key;
    height = 1;
    left = NULL;
    right = NULL;
    label = new QLabel(widget);
    label->setText(QString::number(key));
    label->setStyleSheet("QLabel{border-radius: 20px; background-color: gray; color: white;}");
    label->setAlignment(Qt::AlignCenter);
    pos = new QPointF();
    line_left = new QLineF();
    line_right = new QLineF();
}

template <class T>
T Node<T>::getKey() {
    return key;
}

template <class T>
void Node<T>::setLeft(Node<T>* left) {
    this->left = left;
}

template <class T>
Node<T>* Node<T>::getLeft() {
    return left;
}

template <class T>
void Node<T>::setRight(Node<T>* right) {
    this->right = right;
}

template <class T>
Node<T>* Node<T>::getRight() {
    return right;
}

template <class T>
void Node<T>::refreshPosChild(int& height, int& depth) {
    label->setGeometry(pos->rx(), pos->ry(), 40, 40);
    if (left != NULL) {
        left->pos->setX(pos->rx() - (1.0 / 2.0) * (800.0 / pow(2, height)));
        left->pos->setY(pos->ry() + (556.0 / (depth + 1)) - 22.0);
        line_left->setP1(*pos);
        line_left->setP2(*(left->pos));
    }

    if (right != NULL) {
        right->pos->setX(pos->rx() + (1.0 / 2.0) * (800.0 / pow(2, height)));
        right->pos->setY(pos->ry() + (556/ (depth + 1)) - 22.0);
        line_right->setP1(*pos);
        line_right->setP2(*(right->pos));
    }
}
