#!/bin/bash

if [ -n "$1" ];then
    FILE="$1.cpp";
    if [ -f "$FILE" ];then
        cp "$FILE" sol.cpp
    else
        echo "No file named $FILE"
        exit 1
    fi
fi
echo "Compiling ..."
g++ gen.cpp -o gen.exe -O2 || { echo "gen.cpp compile failed!"; exit 1; }
g++ std.cpp -o std.exe -O2 || { echo "std.cpp compile failed!"; exit 1; }
g++ sol.cpp -o sol.exe -O2 || { echo "sol.cpp compile failed!"; exit 1; }
g++ duipai.cpp -o duipai.exe -O2 || { echo "duipai.cpp compile failed!"; exit 1; }

./duipai.exe;

