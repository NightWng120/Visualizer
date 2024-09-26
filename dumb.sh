#!/bin/bash

gcc -Wall -Wextra -g $(pkg-config --cflags opengl glfw3) /usr/include/glad/glad.c glvisualizer.c \
     $(pkg-config --libs opengl glfw3) -o glvisualizer

