// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>

#include <iostream>
// #include <zlib.h>
// #include <SDL.h>
#include <boost/asio.hpp>
#include <boost/coroutine2/all.hpp>

void foo(boost::coroutines2::coroutine<int>::pull_type &sink)
{
  std::cout << "start coroutine\n";
  int a = sink().get();
  std::cout << a << std::endl;
  std::cout << "finish coroutine\n";
}

int main(int argc, char *argv[])
{

  boost::coroutines2::coroutine<int>::push_type source(foo);
  std::cout << "finish\n";
  source(0);
  source(5);

#ifdef NDEBUG
  printf("Release config\n");
#else
  printf("Debug config\n");
#endif

  // bool quit = false;
  // int W = 800, H = 600;
  // SDL_Window *win = NULL;

  // win = SDL_CreateWindow(
  //     "sdl_win",
  //     SDL_WINDOWPOS_UNDEFINED,
  //     SDL_WINDOWPOS_UNDEFINED,
  //     W,
  //     H,
  //     SDL_WINDOW_SHOWN);

  // while (!quit)
  // {
  //   SDL_Event event;
  //   while (SDL_WaitEvent(&event))
  //   {
  //     if (event.type == SDL_QUIT)
  //     {
  //       quit = true;
  //       break;
  //     }
  //   }
  // }

  return EXIT_SUCCESS;
}
