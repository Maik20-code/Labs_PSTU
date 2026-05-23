#ifndef NODE_H
#define NODE_H


class Node
{
public:
    char* key;
    Node* left;
    Node* right;
    int x, y;
    Node(const char* k);
    ~Node();
};

#endif // NODE_H
