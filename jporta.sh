#!/bin/sh
SOURCE="./src"
TARGET="./jporta_out"
ZIP="./jporta.zip"
# delete zip
rm $ZIP
# delete target directory recursively
rm -rf $TARGET
# recreate target directory
mkdir -p $TARGET
# exclude build/test related files (cmake, memtrace, gtest) but include all the other C/C++ source and header files
find $SOURCE -type f \( ! -iname "*cmake*" -a ! -iname "*memtrace*" -a ! -iname "*gtest*" -a \( -iname "*.c" -o -iname "*.cpp" -o -iname "*.h" -o -iname "*.hpp" \) \) -exec cp -t $TARGET {} +
# this replaces "some/relative/path/bar" with "bar"
find $TARGET -type f -exec sed -i -E "s/\".*\/(.+\.(c|cpp|h|hpp))\"/\"\1\"/g" {} \;
zip -jr $ZIP $TARGET
