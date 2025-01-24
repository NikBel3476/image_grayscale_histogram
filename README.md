## Simple image grayscale histogram

#### project using [qt](https://www.qt.io/)

Building steps:
1. Project configuration: `cmake -B <build directory> -DCMAKE_PREFIX_PATH=<Path to Qt directory> -DCMAKE_BUILD_TYPE=<Debug | Release>`
2. Compiling: `cmake --build <build directory> --parallel`

Executable will be inside build directory

![histogram_example_1](https://github.com/NikBel3476/image_grayscale_histogram/blob/master/example1.png)
![histogram_example_2](https://github.com/NikBel3476/image_grayscale_histogram/blob/master/example2.png)

### steps to build and run executable

**CMake**
1. cmake -B build
2. cmake --build build
3. ./build/qtHistogram

**Meson**
1. meson setup builddir
2. meson compile -C builddir
3. ./builddir/image_grayscale_histogram
