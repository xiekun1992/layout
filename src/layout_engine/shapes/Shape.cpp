#include "Shape.hpp"

Shape::Shape(int x, int y, int width, int height): 
x(x), y(y), width(width), height(height) {
  children = vector<Shape*>();
}

Shape::~Shape() {}

void Shape::traverseNode() {
  cout << "x: " << x << " y: " << y << " width: " << width << " height: " << height << endl;
  for (Shape* child : children) {
    child->traverseNode();
  }
}