#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/vec2.hpp>

namespace GameEngine {

#define MAX_KEYS 512
#define MAX_BUTTONS 32
class Window
{
private:
	
	struct WinData
   	{	
		/*Window*/
		int Width;
		int Height;
		const char* Title;
		
		/*Input*/
		bool Keys[MAX_KEYS];
		bool MouseButtons[MAX_BUTTONS];
		double XPos;
		double YPos;
		
		WinData(int width, int height, const char* title)
			:Width(width), Height(height), Title(title){}
	};

	GLFWwindow* m_Window;
	WinData m_Data;

	bool m_ShouldClose;
public:
	Window(int width, int height, const char* title);
	~Window();
	void Init();
	void Update();
	void Destroy();
	void ProcessInput();
	void SetVSync(bool enable);
	
	bool IsKeyPressed(unsigned int keycode) const;
	bool IsButtonPressed(unsigned int button) const;
	glm::vec2 GetMousePosition() const;

	GLFWwindow* GetWindow() const;
	int GetWidth() const;
	int GetHeight() const;
	int ShouldClose() const;
};

}
