#ifndef _SHAPE_H
#define _SHAPE_H

#include <vector>

class Shape {
  // private:
  public:
    int x, y, width, height;
    std::vector<Shape> children;
    Shape(int x, int y, int width, int height);
    ~Shape();
};

#endif