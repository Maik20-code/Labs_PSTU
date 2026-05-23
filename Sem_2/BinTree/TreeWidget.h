#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "BinaryTree.h"

class TreeWidget : public QWidget {
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    void setTree(BinaryTree* tree);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    BinaryTree* tree;
    void drawNode(QPainter& painter, Node* node);
};

#endif // TREEWIDGET_H
