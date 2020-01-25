#include "Window.h"
#include "Shader.h"
#include "Buffer.h"
#include "IndexBuffer.h"

#include "StaticSprite.h"
#include "Renderable2D.h"

#include "SimpleRenderer2D.h"
#include "BatchRenderer2D.h"

#include <vector>
#include <iostream>

int main()
{
	GameEngine::Window window(1240, 720, "GameEngine");

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	GameEngine::Shader shader("src/shaders/shader.vert", "src/shaders/shader.frag");
	shader.Enable();
	shader.SetUniformMat4f("pr_matrix", ortho);
	shader.SetUniform2f("light_pos", glm::vec2(4.0f, 1.5f));
 
	std::vector<GameEngine::Renderable2D*> sprites;

	for(float y = 0; y < 9.0f; y++)
	{
		for(float x = 0; x < 16.0f; x++)
		{
			sprites.push_back(new GameEngine::Renderable2D(glm::vec3(x, y, 0), glm::vec2(0.9f, 0.9f), glm::vec4(1, 0, 0, 1)));
		}
	}

	GameEngine::Renderable2D* sprite2 = new GameEngine::Renderable2D(glm::vec3(8, 6, 0), glm::vec2(8, 3), glm::vec4(0.5, 0.3, 0.7, 1));	

	GameEngine::BatchRenderer2D renderer;

	while(!window.ShouldClose())
	{
		window.Clear();
		shader.SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()),
				   	(float)(9.0f - window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));
		renderer.Begin();
		for(int i = 0; i < sprites.size(); i++)
		{	
			//renderer.Submit(sprites[i]);
		}
		renderer.Submit(sprite2);
		renderer.End();
		renderer.Flush();

		window.Update();
	}
	delete sprite2;

	return 0;
}
