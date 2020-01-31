################################
#     Makefile Version 1.0     #
#  Created by Tomas Cabrerizo  #
################################

#Compiler Variables
CC = g++
FLAGS = -Wall -Wextra -std=c++14

#Include Directories
INCLUDE_DIR = \
	-I vendor/glad/include \
	-I vendor/glfw/include \
	-I vendor/glm-0.9	\

#Libs Directories
LIBS_DIR = \
	-L vendor/glfw64/lib-mingw-w64 \

#External Libs
LIBS = \
	-lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32

#Source files
SOURCE =  \
	src/*.cpp \
	vendor/glad/src/glad.c 

#Objects files 
OBJECTS = \
	*.o

main: compile
	$(CC) $(FLAGS) -o game $(OBJECTS) $(LIBS_DIR) $(LIBS)

compile: src/*.h 
	$(CC) $(FLAGS) -c -O2 $(SOURCE) $(INCLUDE_DIR) 


