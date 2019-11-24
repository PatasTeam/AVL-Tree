#ifndef CUSTOMPANE_H
#define CUSTOMPANE_H

#include "node.h"
#include "tree.h"

class CustomPane : public QWidget
{
    Q_OBJECT
public:
    explicit CustomPane(QWidget *parent = nullptr);
    void paintPane(Tree<int>* tree);
signals:

private:
    QPainter* paint;
    Tree<int>* temp_tree;
    //virtual void paintEvent(QPaintEvent *);
    void pathRender();
    void pathRenderRec(Node<int>* node);
public slots:
};

#endif // CUSTOMPANE_H
