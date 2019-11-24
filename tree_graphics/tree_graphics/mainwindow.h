#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tree.h"
#include "tree.cpp"
#include "node.h"
#include "node.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    //virtual void paintEvent(QPaintEvent* event);
private slots:

    void on_add_node_clicked();
    void renderNodes(Node<int>* node);
    void on_show_clicked();
private:
    //virtual void paintEvent(QPaintEvent *);
    Tree<int> *tree;
};
#endif // MAINWINDOW_H
