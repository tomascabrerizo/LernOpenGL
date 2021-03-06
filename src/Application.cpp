#include "Window.h"

#include "EngineUtils.h"

#include "StaticSprite.h"
#include "Renderable2D.h"

#include "SimpleRenderer2D.h"
#include "BatchRenderer2D.h"

#include "TileLayer.h"
#include "Group.h"

#include <time.h>
#include <iostream>

#include <FreeImage.h>

#if 1

int main()
{
	GameEngine::Window window(1240, 720, "Game_Engine");

   	srand(time(NULL));
	
	GameEngine::Shader* shader1 = new GameEngine::Shader("src/shaders/shader.vert", "src/shaders/shader.frag");
	GameEngine::Shader* shader2 = new GameEngine::Shader("src/shaders/shader.vert", "src/shaders/shader.frag");

	GameEngine::TileLayer tileLayer(shader1);
	GameEngine::TileLayer tileLayer2(shader2);
	
	GameEngine::Group* gui = new GameEngine::Group(glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.0f)));
	gui->Add(new GameEngine::Renderable2D(glm::vec3(0, 0, 0), glm::vec2(6, 2), glm::vec4(0.8f, 0.8f, 0.8f, 1)));

	GameEngine::Group* button = new GameEngine::Group(glm::translate(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.0f)));
	button->Add(new GameEngine::Renderable2D(glm::vec3(0.0f, 0.0f, 0), glm::vec2(5.6f, 1.6f), glm::vec4(0.2f, 0.2f, 0.2f, 1)));
	button->Add(new GameEngine::Renderable2D(glm::vec3(0.1f, 0.1f, 0), glm::vec2(5.4f, 1.4f), glm::vec4(1.0f, 1.0f, 1.0f, 1)));

	gui->Add(button);

	for(float y = 0; y < 9.0f; y+=0.5f)
	{
		for(float x = 0; x < 16.0f; x+=0.5f)
		{
			tileLayer.Add(new GameEngine::Renderable2D(glm::vec3(x, y, 0), glm::vec2(0.4f, 0.4f), 
						glm::vec4(rand() % 1000 /1000.f, rand() % 1000 /1000.f, rand() % 1000 /1000.f, 1)));
		}
	}
	
	tileLayer2.Add(gui);
	
	GameEngine::Timer& timer = GameEngine::Timer::GetInstance();
	
	while(!window.ShouldClose())
	{
		window.Clear();
		
		timer.Update();
		timer.GetFrameCount(window);
		
		shader1->Enable();
		shader1->SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()), 
					(float)(window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));

		shader2->Enable();
		shader2->SetUniform2f("light_pos", glm::vec2((float)(window.GetMousePosition().x * 16.0f / (float)window.GetWidth()), 
					(float)(window.GetMousePosition().y * 9.0f / (float)window.GetHeight())));

		tileLayer.Render();	
		tileLayer2.Render();

		window.Update();
	}
	
	return 0;
}

#else 

int main()
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//Pointer to the image
	FIBITMAP* dib(0);
	//Pointer to the image Data
	BYTE* bits(0);
	
	fif = FreeImage_GetFileType("test.png", 0);
	dib = FreeImage_Load(fif, "test.png");
	
	bits = FreeImage_GetBits(dib);
	unsigned int width = 0;
	unsigned int height = 0;

	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);

	std::cout << width << " ," << height <<std::endl;
	return 0;
}

#endif
