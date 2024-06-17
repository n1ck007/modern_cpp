#!/bin/bash
# don't include extension, it's assumed to be `.cpp`
SOURCE=$1
clang++ -g -std=c++20 $SOURCE.cpp -o $SOURCE && ./$SOURCE
