#include "TreeWidget.h"
#include <QPainter>
#include <QFont>

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent), tree(nullptr) {}

void TreeWidget::setTree(BinaryTree* t) {
    tree = t;
    if (tree) {
        tree->updateNodePositions(width(), height());
    }
    update();
}

void TreeWidget::paintEvent(QPaintEvent *) {
    if (!tree || !tree->getRoot()) return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font("Arial", 12);
    painter.setFont(font);

    drawNode(painter, tree->getRoot());
}

void TreeWidget::drawNode(QPainter& painter, Node* node) {
    if (!node) return;

    if (node->left) {
        painter.drawLine(node->x, node->y, node->left->x, node->left->y);
        drawNode(painter, node->left);
    }
    if (node->right) {
        painter.drawLine(node->x, node->y, node->right->x, node->right->y);
        drawNode(painter, node->right);
    }

    painter.setBrush(Qt::lightGray);
    painter.drawEllipse(node->x - 20, node->y - 15, 40, 30);
    painter.drawText(node->x - 15, node->y + 5, QString::fromUtf8(node->key));
}
