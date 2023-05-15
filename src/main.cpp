#include <iostream>
#include <Windows.h>
// #include <gl/GL.h>
// #include <gl/GLU.h>
// #include <GLFW/glfw3.h>
#include <GL/glut.h>

#include "layout_engine/Engine.hpp"
#include "layout_engine/shapes/Shape.hpp"
#include "layout_engine/UIConverter.hpp"

int width = 800, height = 600;

void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// void display() {
//   glClear(GL_COLOR_BUFFER_BIT);

//   glBegin(GL_QUADS);
//   glColor3f(1.0, 0.0, 0.0);
//   glVertex2f(-160 * xPixelRatio, 00 * yPixelRatio);
//   glColor3f(0.0, 1.0, 0.0);
//   glVertex2f(-00 * xPixelRatio, 00 * yPixelRatio);
//   glColor3f(0.0, 0.0, 1.0);
//   glVertex2f(-00 * xPixelRatio, 70 * yPixelRatio);
//   glColor3f(1.0, 0.0, 1.0);
//   glVertex2f(-160 * xPixelRatio, 70 * yPixelRatio);
//   glEnd();

//   glFlush();
// }

int main (int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("opengl demo");

  // Shape shape(0, 0, 100, 50);

  UIConverter converter("E:/Desktop/conan-cmake/ui.xml");
  converter.tree->traverseNode();

  Engine engine(width, height);
  engine.layout(converter.tree);

  glutDisplayFunc(initGL);
  // initGL();
  engine.render(converter.tree);
  // display();
  glutMainLoop();
  // while (true) {
  //   Sleep(30);
  //   display();
  // }
  return 0;
}