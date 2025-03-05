#!/bin/bash

BUILD_TYPE=Ninja
BUILD_SUFFIX=ninja

BUILD_FOLDER=build_$BUILD_SUFFIX
SOURCE_FOLDER=projects

if [ ! -d "$BUILD_FOLDER" ]; then
  mkdir "$BUILD_FOLDER"
fi

cd "$BUILD_FOLDER"

cmake -G "$BUILD_TYPE" ../"$SOURCE_FOLDER"
cmake --build .

cp ../"$SOURCE_FOLDER"/dz2.sort/run_merge_sort.bat ./dz2.sort
