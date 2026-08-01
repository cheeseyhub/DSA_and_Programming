#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
private:
    Node* root;

    Node* insert(Node* node, int value);
    void print(Node* node);
    int height(Node* node);
    void updateHeight(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    int balanceFactor(Node* node);
    Node* rebalance(Node* node);

public:
    Tree();
    Node* getRoot();
    void insert(int value);
    void print();
};

#endif // TREE_H
