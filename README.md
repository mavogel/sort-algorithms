# README #

This application and report is just for demonstration purposes. It shows the realization of the **Algorithm Laboratory on the comparison of sorting algorithms**. See report in *documentation* folder for details.

### What is this repository for? ###

* Demonstration of coding
* Test driven approach
* Simplest solution without classes
* Playing with C++14, OpenMP and CMAKE
* Version 1.0

### How do I get set up? ###

* Optional Dependencies: openMP
* Summary of set up:
```
#!bash
mkdir build && cd build
cmake ..
make -j2
./algorithm_lab_time/timeMeasuring
```
* or with an OpenMP capable Compiler

```
#!bash
...
cmake -D CMAKE_CXX_COMPILER=g++-5 -D CMAKE_C_COMPILER=gcc-5 ..
```