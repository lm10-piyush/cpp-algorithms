#! /usr/bin/bash

if [ $# -ge 2 ]
then 
    g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined  -D_GLIBCXX_DEBUG $1
else 
    g++ -std=c++17 $1
fi

