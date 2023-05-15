#include "Engine.hpp"

Engine::Engine(int width, int height) {
  this->width = width;
  this->height = height;
  xPixelRatio = 2 / (float)width;
  yPixelRatio = 2 / (float)height;

  std::cout << xPixelRatio << ", " << yPixelRatio << std::endl;
}

Engine::~Engine() {}

void Engine::layout(Shape* root) {

}

void Engine::render(Shape* root) {
  glClear(GL_COLOR_BUFFER_BIT);
  
  renderShape(root);

  glFlush();
}

void Engine::renderShape(Shape* shape) {
  float left = shape->x  - width / 2.0;
  float top = (shape->y * -1.0) + height / 2.0;
  float right = left + shape->width;
  float bottom = top - shape->height;

  glBegin(GL_QUADS);

  // left bottom
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(left * xPixelRatio, bottom * yPixelRatio);
  // right bottom
  glColor3f(0.0, 1.0, 0.0);
  glVertex2f(right * xPixelRatio, bottom * yPixelRatio);
  // right top
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(right * xPixelRatio, top * yPixelRatio);
  // left top
  glColor3f(1.0, 0.0, 1.0);
  glVertex2f(left * xPixelRatio, top * yPixelRatio);

  glEnd();

  for (Shape* child : shape->children) {
    renderShape(child);
  }
}
void Engine::display() {
}