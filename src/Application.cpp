#include "Window.h"
#include "Shader.h"
#include "Buffer.h"
#include "IndexBuffer.h"

#include "StaticSprite.h"
#include "Renderable2D.h"

#include "SimpleRenderer2D.h"
#include "BatchRenderer2D.h"

#include <vector>
#include <time.h>
#include <iostream>

#define BATCH_RENDERER 1

int main()
{
	GameEngine::Window window(1240, 720, "GameEngine");

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	GameEngine::Shader shader("src/shaders/shader.vert", "src/shaders/shader.frag");
	shader.Enable();
	shader.SetUniformMat4f("pr_matrix", ortho);
	
   	srand(time(NULL));

#if BATCH_RENDERER
	std::vector<GameEngine::Renderable2D*> sprites;
	for(float y = 0; y < 9.0f; y+= 0.1)
	{
		for(float x = 0; x < 16.0f; x += 0.1)
		{
			sprites.push_back(new GameEngine::Renderable2D(glm::vec3(x, y, 0), glm::vec2(0.09f, 0.09f), 
						glm::vec4(rand() % 1000 /1000.f, rand() % 1000 /1000.f, rand() % 1000 /1000.f, 1)));
		}
	}
		
	GameEngine::Renderable2D sprite1(glm::vec3(4.5, 3.5, 0), glm::vec2(2.0f, 2.0f), glm::vec4(1, 0, 0, 1));
	GameEngine::Renderable2D sprite2(glm::vec3(7.0, 3.5, 0), glm::vec2(2.0f, 2.0f), glm::vec4(0, 1, 0, 1));
	GameEngine::Renderable2D sprite3(glm::vec3(9.5, 3.5, 0), glm::vec2(2.0f, 2.0f), glm::vec4(0, 0, 1, 1));
	
	GameEngine::BatchRenderer2D renderer;

#else
	std::vector<GameEngine::StaticSprite*> sprites;

	for(float y = 0; y < 9.0f; y+= 0.1)
	{
		for(float x = 0; x < 16.0f; x += 0.1)
		{
			sprites.push_back(new GameEngine::StaticSprite(glm::vec3(x, y, 0), glm::vec2(0.09f, 0.09f),
					   	glm::vec4(rand() % 1000 /1000.f, rand() % 1000 /1000.f, rand() % 1000 /1000.f, 1), shader));
		}
	}
	
	GameEngine::StaticSprite sprite1(glm::vec3(4.5, 3.5, 0), glm::vec2(2.0f, 2.0f), glm::vec4(1, 0, 0, 1), shader);
	GameEngine::StaticSprite sprite2(glm::vec3(7.0, 3.5, 0), glm::vec2(2.0f, 2.0f), glm::vec4(0, 1, 0, 1), shader);
	GameEngine::StaticSprite sprite3(glm::vec3(9.5, 3.5, 0), glm::vec2(2.0f, 2.0f), glm::vec4(0, 0, 1, 1), shader);

	GameEngine::SimpleRenderer2D renderer;
#endif


	while(!window.ShouldClose())
	{
		window.Clear();
		shader.SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()), (float)(9.0f - window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));
#if BATCH_RENDERER
		renderer.Begin();
#endif
		
		for(std::size_t i = 0; i < sprites.size(); i++)
		{	
			renderer.Submit(sprites[i]);
		}
		renderer.Submit(&sprite1);
		renderer.Submit(&sprite2);
		renderer.Submit(&sprite3);
		
#if BATCH_RENDERER
		renderer.End();
#endif
		renderer.Flush();
		window.Update();
	}

	return 0;
}
