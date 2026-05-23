#include "BinaryTree.h"
#include <cstdlib>
#include <algorithm>
#include <cstring>

BinaryTree::BinaryTree() : root(nullptr) {}
BinaryTree::~BinaryTree() {
    clear(root);
}
void BinaryTree::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
void BinaryTree::insertNode(Node*& node, const char* key) {
    if (node == nullptr) {
        node = new Node(key);
    } else {
        int keyVal = atoi(key);
        int nodeVal = atoi(node->key);
        if (keyVal < nodeVal) {
            insertNode(node->left, key);
        } else if (keyVal > nodeVal) {
            insertNode(node->right, key);
        }
    }
}
void BinaryTree::insert(const char* key) {
    insertNode(root, key);
}

Node* BinaryTree::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

Node* BinaryTree::deleteNode(Node* node, const char* key) {
    if (node == nullptr) return nullptr;
    int keyVal = atoi(key);
    int nodeVal = atoi(node->key);
    if (keyVal < nodeVal) {
        node->left = deleteNode(node->left, key);
    } else if (keyVal > nodeVal) {
        node->right = deleteNode(node->right, key);
    } else {
        // узел найден
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        char* newKey = new char[std::strlen(temp->key) + 1];
        std::strcpy(newKey, temp->key);
        delete[] node->key;
        node->key = newKey;
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

bool BinaryTree::remove(const char* key) {
    if (!search(key)) return false;
    root = deleteNode(root, key);
    return true;
}

bool BinaryTree::searchNode(Node* node, const char* key) const {
    if (node == nullptr) return false;
    int keyVal = atoi(key);
    int nodeVal = atoi(node->key);
    if (keyVal == nodeVal) return true;
    if (keyVal < nodeVal) return searchNode(node->left, key);
    else return searchNode(node->right, key);
}

bool BinaryTree::search(const char* key) const {
    return searchNode(root, key);
}

void BinaryTree::preOrder(Node* node, std::vector<const char*>& result) const {
    if (node) {
        result.push_back(node->key);
        preOrder(node->left, result);
        preOrder(node->right, result);
    }
}

std::vector<const char*> BinaryTree::preOrderTraversal() const {
    std::vector<const char*> result;
    preOrder(root, result);
    return result;
}

void BinaryTree::inOrder(Node* node, std::vector<const char*>& result) const {
    if (node) {
        inOrder(node->left, result);
        result.push_back(node->key);
        inOrder(node->right, result);
    }
}

std::vector<const char*> BinaryTree::inOrderTraversal() const {
    std::vector<const char*> result;
    inOrder(root, result);
    return result;
}

void BinaryTree::postOrder(Node* node, std::vector<const char*>& result) const {
    if (node) {
        postOrder(node->left, result);
        postOrder(node->right, result);
        result.push_back(node->key);
    }
}

std::vector<const char*> BinaryTree::postOrderTraversal() const {
    std::vector<const char*> result;
    postOrder(root, result);
    return result;
}

int BinaryTree::countStartingWith(Node* node, char ch) const {
    if (!node) return 0;
    int cnt = (node->key[0] == ch) ? 1 : 0;
    cnt += countStartingWith(node->left, ch);
    cnt += countStartingWith(node->right, ch);
    return cnt;
}

int BinaryTree::countStartingWith(char ch) const {
    return countStartingWith(root, ch);
}

int BinaryTree::getHeight(Node* node) const {
    if (!node) return 0;
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

void BinaryTree::balanceTree() {
    std::vector<const char*> keys = inOrderTraversal();
    if (keys.empty()) return;

    std::vector<const char*> copies;
    for (const char* s : keys) {
        char* copy = new char[std::strlen(s) + 1];
        std::strcpy(copy, s);
        copies.push_back(copy);
    }

    clear(root);
    root = nullptr;

    root = balance(copies, 0, copies.size() - 1);

    for (const char* c : copies) {
        delete[] const_cast<char*>(c);
    }
}

Node* BinaryTree::balance(std::vector<const char*>& keys, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* node = new Node(keys[mid]);
    node->left = balance(keys, start, mid - 1);
    node->right = balance(keys, mid + 1, end);
    return node;
}

void BinaryTree::computeNodePositions(Node* node, int x, int y, int xOffset) {
    if (!node) return;
    node->x = x;
    node->y = y;
    computeNodePositions(node->left, x - xOffset, y + 80, xOffset / 2);
    computeNodePositions(node->right, x + xOffset, y + 80, xOffset / 2);
}

void BinaryTree::updateNodePositions(int width, int height) {
    if (!root) return;
    int startX = width / 2;
    int startY = 50;
    int initialOffset = width / 4;
    computeNodePositions(root, startX, startY, initialOffset);
}
