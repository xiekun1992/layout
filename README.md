# custom layout engine for fun

## Prerequisites
- python3 + pip
- conan2
- cmake
- c++ toolchain
## Build
- conan install . --output-folder=build --build=missing --settings=build_type=Debug
- cd build
- cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
- cmake --build .

## Run
- ./build/Debug/layout.exe