#! /bin/sh

build_dir="./build"

if [ ! -d $build_dir ]
then
    mkdir build
fi

cd build
cmake ..
make

./game
