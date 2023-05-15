#ifndef _ENGINE_H
#define _ENGINE_H

#include <vector>
#include <GL/glut.h>
#include "./shapes/Shape.hpp"

class Engine {
  private:
    float xPixelRatio, yPixelRatio;
    int width, height;
  public:
    Shape* layoutTree;
    Engine(int width, int height);
    ~Engine();

    void layout(Shape* root);
    void render(Shape* root);
    void renderShape(Shape* shape);
    void display();
};

#endif