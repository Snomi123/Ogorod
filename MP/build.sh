#!/bin/bash

BUILD_TYPE=Ninja
BUILD_SUFFIX=ninja
BUILD_FOLDER=build_$BUILD_SUFFIX
SOURCE_FOLDER=projects/dz4.long_number  

mkdir -p "$BUILD_FOLDER"
cd "$BUILD_FOLDER"

cmake -G "$BUILD_TYPE" ../"$SOURCE_FOLDER"

cmake --build .

ctest --output-on-failure
