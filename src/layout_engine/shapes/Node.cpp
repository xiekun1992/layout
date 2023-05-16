#include "Node.hpp"

Node::Node(int x, int y, int width, int height): 
x(x), y(y), width(width), height(height) {
  children = std::vector<Node*>();
}

Node::~Node() {}

void Node::traverseNode() {
  std::cout << "x: " << x << " y: " << y << " width: " << width << " height: " << height << std::endl;
  for (Node* child : children) {
    child->traverseNode();
  }
}