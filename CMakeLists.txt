cmake_minimum_required(VERSION 3.6)

project(Game)

set(VENDOR ${PROJECT_SOURCE_DIR}/vendor)

file(GLOB files_SRC
	"src/*.h"
	"src/*.cpp"
	"${VENDOR}/glad/src/glad.c"	
	)

include_directories(
	${VENDOR}/freeglut/include
	${VENDOR}/glfw/include
	${VENDOR}/glad/include
	)
link_directories(
	${VENDOR}/freeglut/lib/x64
	${VENDOR}/glfw/lib-vc2019	
	)

add_executable(game ${files_SRC})

target_link_libraries(game 
	glfw3
	freeglut
	opengl32
	gdi32
	user32
	kernel32	
	)
