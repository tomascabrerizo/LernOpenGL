#include "Window.h"
#include "Shader.h"
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>

int main()
{
	GameEngine::Window window(1024, 720, "GameEngine");
	
	GLfloat vertices[] = 
	{
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
	 	-0.5f, -0.5f, 0.0f,
	   	-0.5f,  0.5f, 0.0f,	
		 0.5f,  0.5f, 0.0f,
	 	-0.5f, -0.5f, 0.0f
	};
	
	GLuint vbo, vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	
	glm::mat4 ortho = glm::ortho(0.0f, 2.0f, 0.0f, 1.0f, -1.0f, 1.0f);

	GameEngine::Shader shader("src/shaders/shader.vert", "src/shaders/shader.frag");
	shader.Enable();
	shader.SetUniformMat4f(ortho);

	while(!window.ShouldClose())
	{
		glClearColor(0.4f, 0.3f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.Update();
	}

	return 0;
}
