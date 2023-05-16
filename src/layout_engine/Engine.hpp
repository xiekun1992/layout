#ifndef _ENGINE_H
#define _ENGINE_H

#include <vector>
#include <GL/glut.h>
#include "./shapes/Node.hpp"

class Engine {
  private:
    float xPixelRatio, yPixelRatio;
    int width, height;
  public:
    Node* layoutTree;
    Engine(int width, int height);
    ~Engine();

    void layout(Node* root);
    void render(Node* root);
    void renderShape(Node* shape);
    void display();
};

#endif