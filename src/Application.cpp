#include "Window.h"

#include "EngineUtils.h"

#include "StaticSprite.h"
#include "Renderable2D.h"

#include "SimpleRenderer2D.h"
#include "BatchRenderer2D.h"

#include "TileLayer.h"

#include <time.h>
#include <iostream>

int main()
{
	GameEngine::Window window(1240, 720, "Game_Engine");

   	srand(time(NULL));
	
	GameEngine::Shader* shader1 = new GameEngine::Shader("src/shaders/shader.vert", "src/shaders/shader.frag");
	GameEngine::Shader* shader2 = new GameEngine::Shader("src/shaders/shader.vert", "src/shaders/shader.frag");

	GameEngine::TileLayer tileLayer(shader1);
	GameEngine::TileLayer tileLayer2(shader2);

	for(float y = 0; y < 9.0f; y+=0.5f)
	{
		for(float x = 0; x < 16.0f; x+=0.5f)
		{
			tileLayer.Add(new GameEngine::Renderable2D(glm::vec3(x, y, 0), glm::vec2(0.4f, 0.4f), 
						glm::vec4(rand() % 1000 /1000.f, rand() % 1000 /1000.f, rand() % 1000 /1000.f, 1)));
		}
	}
	
	tileLayer2.Add(new GameEngine::Renderable2D(glm::vec3(0, 0, 0), glm::vec2(4.0f, 9.0f), glm::vec4(1, 0, 0, 1)));

	while(!window.ShouldClose())
	{
		window.Clear();
		
		GameEngine::Timer::GetInstance().Update();
		GameEngine::Timer::GetInstance().GetFrameCount(window);
		
		shader1->Enable();
		shader1->SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()), 
					(float)(window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));
		//shader2->Enable();
		//shader2->SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()), 
		//			(float)(window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));

		tileLayer.Render();	
		tileLayer2.Render();

		window.Update();
	}
	
	return 0;
}
