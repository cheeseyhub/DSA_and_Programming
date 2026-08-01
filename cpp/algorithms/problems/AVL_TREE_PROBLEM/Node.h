#ifndef NODE_H
#define NODE_H

class Node {
public:
    int value, height;
    Node* left;
    Node* right;

    Node(int v);

    int getHeight();
    int getValue();
    Node* getLeft();
    Node* getRight();

    void setLeft(Node* n);
    void setRight(Node* n);
    void setHeight(int h);
};

#endif // NODE_H
