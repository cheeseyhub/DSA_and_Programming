#include "Node.h"

Node::Node(int v) : value(v), height(0), left(nullptr), right(nullptr) {}

int Node::getHeight() { return height; }
int Node::getValue() { return value; }
Node* Node::getLeft() { return left; }
Node* Node::getRight() { return right; }

void Node::setLeft(Node* n) { left = n; }
void Node::setRight(Node* n) { right = n; }
void Node::setHeight(int h) { height = h; }
