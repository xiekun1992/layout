#include <iostream>
#include <Windows.h>
// #include <gl/GL.h>
// #include <gl/GLU.h>
// #include <GLFW/glfw3.h>
#include <GL/glut.h>

int width = 320, height = 320;
float xPixelRatio = 2 / (float)width;
float yPixelRatio = 2 / (float)height;

void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-160 * xPixelRatio, 00 * yPixelRatio);
  glColor3f(0.0, 1.0, 0.0);
  glVertex2f(-00 * xPixelRatio, 00 * yPixelRatio);
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(-00 * xPixelRatio, 70 * yPixelRatio);
  glColor3f(1.0, 0.0, 1.0);
  glVertex2f(-160 * xPixelRatio, 70 * yPixelRatio);
  glEnd();

  glFlush();
}

int main (int argc, char *argv[]) {
  std::cout << xPixelRatio << ", " << yPixelRatio << std::endl;

  glutInit(&argc, argv);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("opengl demo");
  glutDisplayFunc(display);
  initGL();
  glutMainLoop();

  return 0;
}