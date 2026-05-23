#include "MainWindow.h"
#include "TreeWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget* central = new QWidget;
    setCentralWidget(central);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    treeWidget = new TreeWidget;
    treeWidget->setMinimumSize(800, 500);
    mainLayout->addWidget(treeWidget, 1);

    // Панель ввода ключа
    QHBoxLayout* inputLayout = new QHBoxLayout;
    QLabel* keyLabel = new QLabel("Ключ:");
    keyEdit = new QLineEdit;
    inputLayout->addWidget(keyLabel);
    inputLayout->addWidget(keyEdit);
    mainLayout->addLayout(inputLayout);

    // Кнопки основных операций
    QHBoxLayout* btnLayout = new QHBoxLayout;
    insertBtn = new QPushButton("Вставить");
    deleteBtn = new QPushButton("Удалить");
    searchBtn = new QPushButton("Поиск");
    balanceBtn = new QPushButton("Балансировать");
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(deleteBtn);
    btnLayout->addWidget(searchBtn);
    btnLayout->addWidget(balanceBtn);
    mainLayout->addLayout(btnLayout);

    QHBoxLayout* countLayout = new QHBoxLayout;
    QLabel* charLabel = new QLabel("Символ:");
    charEdit = new QLineEdit;
    charEdit->setMaxLength(1);
    countBtn = new QPushButton("Подсчитать элементы, начинающиеся с символа");
    countLayout->addWidget(charLabel);
    countLayout->addWidget(charEdit);
    countLayout->addWidget(countBtn);
    mainLayout->addLayout(countLayout);

    QHBoxLayout* traversalLayout = new QHBoxLayout;
    preBtn = new QPushButton("Прямой обход");
    inBtn = new QPushButton("Симметричный обход");
    postBtn = new QPushButton("Обратный обход");
    traversalLayout->addWidget(preBtn);
    traversalLayout->addWidget(inBtn);
    traversalLayout->addWidget(postBtn);
    mainLayout->addLayout(traversalLayout);

    outputEdit = new QTextEdit;
    outputEdit->setReadOnly(true);
    mainLayout->addWidget(outputEdit);

    connect(insertBtn, &QPushButton::clicked, this, &MainWindow::onInsert);
    connect(deleteBtn, &QPushButton::clicked, this, &MainWindow::onDelete);
    connect(searchBtn, &QPushButton::clicked, this, &MainWindow::onSearch);
    connect(balanceBtn, &QPushButton::clicked, this, &MainWindow::onBalance);
    connect(countBtn, &QPushButton::clicked, this, &MainWindow::onCountStarting);
    connect(preBtn, &QPushButton::clicked, this, &MainWindow::onPreOrder);
    connect(inBtn, &QPushButton::clicked, this, &MainWindow::onInOrder);
    connect(postBtn, &QPushButton::clicked, this, &MainWindow::onPostOrder);

    setWindowTitle("Бинарное дерево поиска (char*)");
    resize(900, 700);
}

MainWindow::~MainWindow() {}

void MainWindow::updateTreeDisplay() {
    treeWidget->setTree(&tree);
}

void MainWindow::showMessage(const QString& msg) {
    outputEdit->append(msg);
}

void MainWindow::onInsert() {
    QString qkey = keyEdit->text().trimmed();
    if (qkey.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите ключ");
        return;
    }
    QByteArray ba = qkey.toUtf8();
    const char* key = ba.constData();
    if (tree.search(key)) {
        showMessage("Элемент уже существует: " + qkey);
    } else {
        tree.insert(key);
        showMessage("Вставлен: " + qkey);
        updateTreeDisplay();
    }
    keyEdit->clear();
}

void MainWindow::onDelete() {
    QString qkey = keyEdit->text().trimmed();
    if (qkey.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите ключ");
        return;
    }
    QByteArray ba = qkey.toUtf8();
    const char* key = ba.constData();
    if (tree.remove(key)) {
        showMessage("Удалён: " + qkey);
        updateTreeDisplay();
    } else {
        showMessage("Элемент не найден: " + qkey);
    }
    keyEdit->clear();
}

void MainWindow::onSearch() {
    QString qkey = keyEdit->text().trimmed();
    if (qkey.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите ключ");
        return;
    }
    QByteArray ba = qkey.toUtf8();
    const char* key = ba.constData();
    bool found = tree.search(key);
    showMessage(found ? "Элемент найден: " + qkey : "Элемент не найден: " + qkey);
    keyEdit->clear();
}

void MainWindow::onBalance() {
    tree.balanceTree();
    updateTreeDisplay();
    showMessage("Дерево сбалансировано.");
}

void MainWindow::onCountStarting() {
    QString chStr = charEdit->text().trimmed();
    if (chStr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите символ");
        return;
    }
    char ch = chStr[0].toLatin1();
    int count = tree.countStartingWith(ch);
    showMessage("Количество элементов, начинающихся с '" + QString(ch) + "': " + QString::number(count));
}

void MainWindow::onPreOrder() {
    auto res = tree.preOrderTraversal();
    QString msg = "Прямой обход: ";
    for (const char* s : res) {
        msg += QString::fromUtf8(s) + " ";
    }
    showMessage(msg);
}

void MainWindow::onInOrder() {
    auto res = tree.inOrderTraversal();
    QString msg = "Симметричный обход: ";
    for (const char* s : res) {
        msg += QString::fromUtf8(s) + " ";
    }
    showMessage(msg);
}

void MainWindow::onPostOrder() {
    auto res = tree.postOrderTraversal();
    QString msg = "Обратный обход: ";
    for (const char* s : res) {
        msg += QString::fromUtf8(s) + " ";
    }
    showMessage(msg);
}
