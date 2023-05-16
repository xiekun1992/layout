#ifndef _NODE_H
#define _NODE_H

// #include <cstddef>
#include <vector>
#include <iostream>

class Node {
  // private:
  public:
    int x, y, width, height;
    std::vector<Node*> children;
    Node* parent;
    Node(int x, int y, int width, int height);
    ~Node();
    void traverseNode();
};

#endif