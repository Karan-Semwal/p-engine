#! /bin/sh

build_dir="./build"
bin_dir="./bin"

if [ -d $build_dir ]
then
    rm -rf build
fi

mkdir build
clear
echo "Cleaned!"