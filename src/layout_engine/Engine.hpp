#ifndef _ENGINE_H
#define _ENGINE_H

#include "./shapes/Shape.hpp"
#include <vector>

class Engine {
  // private:
  public:
    Shape* layoutTree;
    Engine();
    ~Engine();
};

#endif