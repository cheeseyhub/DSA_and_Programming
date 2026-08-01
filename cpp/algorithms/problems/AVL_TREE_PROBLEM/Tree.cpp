#include "Tree.h"
#include <iostream>
#include <algorithm>

Tree::Tree() : root(nullptr) {}

Node* Tree::getRoot() {
    return root;
}

void Tree::insert(int value) {
    root = insert(root, value);
}

Node* Tree::insert(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->getValue())
        node->setLeft(insert(node->getLeft(), value));
    else if (value > node->getValue())
        node->setRight(insert(node->getRight(), value));
    else
        return node;

    updateHeight(node);
    return rebalance(node);
}

void Tree::print() {
    print(root);
}

void Tree::print(Node* node) {
    if (node != nullptr) {
        std::cout << node->getValue() << " ";
        print(node->getLeft());
        print(node->getRight());
    }
}

int Tree::height(Node* node) {
    return node != nullptr ? node->getHeight() : -1;
}

void Tree::updateHeight(Node* node) {
    int leftChildHeight = height(node->getLeft());
    int rightChildHeight = height(node->getRight());
    node->setHeight(std::max(leftChildHeight, rightChildHeight) + 1);
}

Node* Tree::rotateLeft(Node* node) {
    Node* rightChild = node->getRight();
    node->setRight(rightChild->getLeft());
    rightChild->setLeft(node);

    updateHeight(node);
    updateHeight(rightChild);

    return rightChild;
}

Node* Tree::rotateRight(Node* node) {
    Node* leftChild = node->getLeft();
    node->setLeft(leftChild->getRight());
    leftChild->setRight(node);

    updateHeight(node);
    updateHeight(leftChild);

    return leftChild;
}

int Tree::balanceFactor(Node* node) {
    return height(node->getLeft()) - height(node->getRight());
}

Node* Tree::rebalance(Node* node) {
    int balanceFactor = this->balanceFactor(node);

    if (balanceFactor > 1) {
        if (this->balanceFactor(node->getLeft()) > 0) {
            node = rotateRight(node);
        } else {
            node->setLeft(rotateLeft(node->getLeft()));
            node = rotateRight(node);
        }
    } else if (balanceFactor < -1) {
        if (this->balanceFactor(node->getRight()) < 0) {
            node = rotateLeft(node);
        } else {
            node->setRight(rotateRight(node->getRight()));
            node = rotateLeft(node);
        }
    }

  return node;
}
