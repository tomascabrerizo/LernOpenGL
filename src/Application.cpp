#include "Window.h"
#include "Shader.h"
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

#include "SimpleRenderer2D.h"
#include "Renderable2D.h"

int main()
{
	GameEngine::Window window(1240, 720, "GameEngine");

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	GameEngine::Shader shader("src/shaders/shader.vert", "src/shaders/shader.frag");
	shader.Enable();
	shader.SetUniformMat4f("pr_matrix", ortho);
	shader.SetUniform2f("light_pos", glm::vec2(4.0f, 1.5f));
	
	GameEngine::Renderable2D sprite0(glm::vec3(0, 0, 0), glm::vec2(8, 3), glm::vec4(0.5, 0.3, 0.7, 1), shader);
	GameEngine::Renderable2D sprite1(glm::vec3(4, 3, 0), glm::vec2(8, 3), glm::vec4(0.5, 0.5, 0.7, 1), shader);
	GameEngine::Renderable2D sprite2(glm::vec3(8, 6, 0), glm::vec2(8, 3), glm::vec4(0.5, 0.3, 0.7, 1), shader);

	GameEngine::SimpleRenderer2D renderer;

	while(!window.ShouldClose())
	{
		window.Clear();
		shader.SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()),
				   	(float)(9.0f - window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));
	
		renderer.Submit(&sprite0);
		renderer.Submit(&sprite1);
		renderer.Submit(&sprite2);
		renderer.Flush();

		window.Update();
	}

	return 0;
}
