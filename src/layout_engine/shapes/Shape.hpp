#ifndef _SHAPE_H
#define _SHAPE_H

#include <vector>
#include <iostream>

using namespace std;

class Shape {
  // private:
  public:
    int x, y, width, height;
    vector<Shape*> children;
    Shape* parent;
    Shape(int x, int y, int width, int height);
    ~Shape();
    void traverseNode();
};

#endif