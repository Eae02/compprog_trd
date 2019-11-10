#!/bin/bash
g++ --std=c++17 -Wall -Wshadow -Wno-conversion -ftrapv -g $1 -o ${1%.cpp}.bin
