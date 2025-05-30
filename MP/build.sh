#!/bin/bash

BUILD_DIR="build"
PROJECT_DIR="projects/dz5.vector_list"

rm -rf $BUILD_DIR

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake ../$PROJECT_DIR -DCMAKE_BUILD_TYPE=Debug

cmake --build . -- -j$(sysctl -n hw.ncpu)

ctest --output-on-failure
