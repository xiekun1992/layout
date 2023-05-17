cmake_minimum_required(VERSION 3.15)
# project(compressor C)
project(layout CXX)

set(
  SOURCES
  src/main.cpp
  src/layout_engine/UIConverter.cpp
  src/layout_engine/shapes/Node.cpp
  src/layout_engine/Engine.cpp
  src/layout_engine/layouts/Flow.cpp
)
# find_package(ZLIB REQUIRED)
# find_package(SDL2 REQUIRED)
# find_package(Boost REQUIRED)
find_package(GLUT REQUIRED)
# find_package(rapidxml REQUIRED)
# find_package(glfw3 REQUIRED)

message("Building with CMake version: ${CMAKE_VERSION}")

# add_executable(${PROJECT_NAME} WIN32 src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(
  ${PROJECT_NAME} 
  # SDL2::SDL2 SDL2::SDL2main 
  # Boost::coroutine 
  GLUT::GLUT 
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)