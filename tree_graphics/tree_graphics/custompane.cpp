#include <iostream>

#include "custompane.h"
using namespace std;

CustomPane::CustomPane(QWidget *parent) : QWidget(parent) {
    temp_tree = NULL;
    //paint = new QPainter(this);
}

/*
void CustomPane::paintEvent(QPaintEvent *event) {
    if (temp_tree != NULL) {
        pathRenderRec(temp_tree->getRoot());
    }
}


void CustomPane::pathRender() {
    pathRenderRec(temp_tree->getRoot());
    update();
    cout << "ok" << endl;
}

void CustomPane::pathRenderRec(Node<int> *node) {
    if (node != NULL) {
        cout << "KEY RENDER: " << node->getKey() << endl;
        paint->drawLine(*node->line_left);
        paint->drawLine(*node->line_left);
        pathRenderRec(node->getLeft());
        pathRenderRec(node->getRight());
    }
}

void CustomPane::paintPane(Tree<int> *tree) {
    temp_tree = tree;
    update();
}
*/
