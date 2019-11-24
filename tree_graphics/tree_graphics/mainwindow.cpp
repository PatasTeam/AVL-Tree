#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    tree = new Tree<int>(ui->centralwidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_add_node_clicked() {
    tree->insert(ui->key_input->text().toInt());
}

void MainWindow::renderNodes(Node<int>* node) {
    if (node != nullptr) {
        node->label->show();
        renderNodes(node->getLeft());
        renderNodes(node->getRight());
    }
}

void MainWindow::on_show_clicked() {
    renderNodes(tree->getRoot());
    tree->print2D();
    tree->calculateDepth();
}
