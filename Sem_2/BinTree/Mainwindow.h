#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BinaryTree.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
class QTextEdit;
class QPushButton;
class TreeWidget;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInsert();
    void onDelete();
    void onSearch();
    void onBalance();
    void onCountStarting();
    void onPreOrder();
    void onInOrder();
    void onPostOrder();

private:
    BinaryTree tree;
    TreeWidget* treeWidget;
    QLineEdit* keyEdit;
    QTextEdit* outputEdit;
    QPushButton* insertBtn;
    QPushButton* deleteBtn;
    QPushButton* searchBtn;
    QPushButton* balanceBtn;
    QPushButton* countBtn;
    QPushButton* preBtn;
    QPushButton* inBtn;
    QPushButton* postBtn;
    QLineEdit* charEdit;

    void updateTreeDisplay();
    void showMessage(const QString& msg);
};

#endif // MAINWINDOW_H
