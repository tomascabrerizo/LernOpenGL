#include "Window.h"
#include <iostream>
#include <cstring>

namespace GameEngine {

Window::Window(int width, int height, const char* title)
	:m_Data(width, height, title)
{
	//set all values of the array to 0
	memset(m_Data.Keys, 0, sizeof(bool)*MAX_KEYS);
	memset(m_Data.MouseButtons, 0, sizeof(bool)*MAX_BUTTONS);

	//Initiallize the windows
	Init();
}

Window::~Window()
{
	Destroy();
}

void Window::Init()
{
	/*Init GLFW*/
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/*Create GLFW window*/
	m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, NULL, NULL);
	if(NULL == m_Window)
	{
		std::cout << "Error: could not create GLFW window" << std::endl;
	}

	/*Create context for openGL*/
	glfwMakeContextCurrent(m_Window);
	SetVSync(true);
	
	glfwSetWindowUserPointer(m_Window, &m_Data);

	//Lambda funtion to set the resize callback
	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
	{
		WinData& data = *(WinData*)glfwGetWindowUserPointer(window);
		data.Width = width;
		data.Height = height;
		glViewport(0, 0, data.Width, data.Height);
	});

	//Lambda function to set the keys callback
	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode,int action, int mods)
	{
		WinData& data = *(WinData*)glfwGetWindowUserPointer(window);
		data.Keys[key] = action != GLFW_RELEASE;

	});

	//Lambda function to set mouse buttons callback
	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
	{
		WinData& data = *(WinData*)glfwGetWindowUserPointer(window);
		data.MouseButtons[button] = action != GLFW_RELEASE;	
	});

	//Lambda function to set cursor position
	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
	{
		WinData& data = *(WinData*)glfwGetWindowUserPointer(window);
		data.XPos = xpos;
		data.YPos = ypos;
	});

	//Init GLAD to get modern OpenGL
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Error: GLAD could not be initiallized" << std::endl; 
	}
	
}

void Window::Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::Update()
{
	GLenum error = glGetError();
	if(error != GL_NO_ERROR)
		std::cout << "OpenGL Error: " << error << std::endl;

	ProcessInput();
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Window::Destroy()
{
	glfwTerminate();
}

void Window::ProcessInput()
{
	if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
}

void Window::SetVSync(bool enable)
{
	if(enable)
	{
		glfwSwapInterval(1);
	}
	else
	{
		glfwSwapInterval(0);
	}
}

bool Window::IsKeyPressed(unsigned int keycode) const
{
	if(keycode > MAX_KEYS)
	{
		return false;
	}

	return m_Data.Keys[keycode];
}

bool Window::IsButtonPressed(unsigned int button) const
{
	if(button > MAX_BUTTONS)
	{
		return false;
	}
	
	return m_Data.MouseButtons[button];
}

glm::vec2 Window::GetMousePosition() const
{
	return glm::vec2(m_Data.XPos, m_Data.YPos);
}

GLFWwindow* Window::GetWindow() const
{
	return m_Window;
}
int Window::GetWidth() const
{
	return m_Data.Width;
}

int Window::GetHeight() const
{
	return m_Data.Height;
}

int Window::ShouldClose() const
{
	return glfwWindowShouldClose(m_Window);
}

}
