#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <Node.h>
#include <vector>

class BinaryTree
{
private:
    Node* root;
    void insertNode(Node*& node, const char* key);
    Node* findMin(Node* node);
    Node* deleteNode(Node* node, const char* key);
    bool searchNode(Node* node, const char* key) const;
    void preOrder(Node* node, std::vector<const char*>& result) const;
    void inOrder(Node* node, std::vector<const char*>& result) const;
    void postOrder(Node* node, std::vector<const char*>& result) const;
    int countStartingWith(Node* node, char ch) const;
    Node* balance(std::vector<const char*>& keys, int start, int end);
    void clear(Node* node);
    int getHeight(Node* node) const;
    void computeNodePositions(Node* node, int x, int y, int xOffset);
public:
    BinaryTree();
    ~BinaryTree();

    void insert(const char* key);
    bool remove(const char* key);
    bool search(const char* key) const;
    std::vector<const char*> preOrderTraversal() const;
    std::vector<const char*> inOrderTraversal() const;
    std::vector<const char*> postOrderTraversal() const;
    int countStartingWith(char ch) const;
    void balanceTree();
    Node* getRoot() const { return root; }
    void updateNodePositions(int width, int height);
};

#endif // BINARYTREE_H
