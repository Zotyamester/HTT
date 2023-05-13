#!/bin/sh
SOURCE="./src"
TARGET="./jporta_out"
# delete target directory recursively
rm -rf $TARGET
# recreate target directory
mkdir -p $TARGET
# exclude cmake related files but include all C/C++ source and header files
find $SOURCE -type f \( ! -iname "*cmake*" -a \( -iname "*.c" -o -iname "*.cpp" -o -iname "*.h" -o -iname "*.hpp" \) \) -exec cp -t $TARGET {} +
# this replaces "../bar" with "bar"
find $TARGET -type f -exec sed -i -E "s/\.\.(\/.*)*\/(.+)/\2/g" {} \;
