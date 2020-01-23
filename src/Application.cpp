#include "Window.h"
#include "Shader.h"
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

int main()
{
	GameEngine::Window window(1240, 720, "GameEngine");

	GLfloat vertices[] = 
	{
	 	0.0f, 0.0f, 0.0f,
	   	0.0f, 3.0f, 0.0f,	
		8.0f, 3.0f, 0.0f,
		8.0f, 0.0f, 0.0f,
	};

	GLushort indices[] = 
	{
		0, 1, 2,
		2, 3, 0
	};

	GameEngine::VertexArray vao;
	GameEngine::Buffer* vbo = new GameEngine::Buffer(vertices, 4 * 3, 3);
	GameEngine::IndexBuffer ibo(indices, 6);

	vao.AddBuffer(vbo, 0);

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	GameEngine::Shader shader("src/shaders/shader.vert", "src/shaders/shader.frag");
	shader.Enable();
	shader.SetUniformMat4f("pr_matrix", ortho);
	shader.SetUniformMat4f("ml_matrix", glm::translate(glm::mat4(1.0f), glm::vec3(4, 3, 0)));
	shader.SetUniform2f("light_pos", glm::vec2(4.0f, 1.5f));
	shader.SetUniform4f("ml_color", glm::vec4(0.3f, 0.12f, 0.6f, 1.0f));

	while(!window.ShouldClose())
	{
		window.Clear();
		shader.SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()),
				   	(float)(9.0f - window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));
		vao.Bind();	
		ibo.Bind();
		shader.SetUniformMat4f("ml_matrix", glm::translate(glm::mat4(1.0f), glm::vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		shader.SetUniformMat4f("ml_matrix", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		ibo.Unbind();
		vao.Unbind();

		window.Update();
	}

	return 0;
}
