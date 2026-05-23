#include "Node.h"
#include <cstring>

Node::Node(const char* k)
{
    key = new char[std::strlen(k)+1];
    strcpy_s(key, strlen(k) + 1, k);
    left = nullptr;
    right = nullptr;
    x = y = 0;
}
Node::~Node() {
    delete[] key;
}
