##Game makefile
main: 
	g++ -Wall -std=c++14 \
	src/*.cpp vendor/glad/src/glad.c \
	-o game \
	-I vendor/glad/include \
	-I vendor\glfw\include \
	-I vendor\glm-0.9	\
	-L vendor\glfw\lib-mingw-w64 \
	-lglfw3 -lopengl32 -luser32 -lgdi32 -lkernel32 
