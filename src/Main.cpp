#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/mat4x4.hpp>

/*Function to resize the OpenGL Viewport*/
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


int main(int argc, char** argv) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/*Init GLFW windows*/
	GLFWwindow* window = glfwCreateWindow(800, 600, "No Microsoft Compiler Bitch!", NULL, NULL);
	if(NULL == window)
	{
		printf("failed creating windows");
		
		glfwTerminate();
		return -1;
	}

	/*Create context for OpenGL*/
	glfwMakeContextCurrent(window);

	/*Init GLAD*/
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("failed to initialize GLAD");

		return -1;
	}
	
	glViewport(0, 0, 800, 600);

	/*Every time the windows is resize call the callback buffer resize function*/
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	/*Init the while LOOP*/
	while(!glfwWindowShouldClose(window))
	{
		processInput(window);

		/*Rendering Commands*/
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
