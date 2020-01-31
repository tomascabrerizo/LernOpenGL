#include "EngineUtils.h"
#include "Window.h"
#include <sstream>

namespace GameEngine {

//Function to reaad text files	
	std::string Read_File(const char* filepath)
	{
		std::fstream file;
		file.open(filepath, std::ios::in);
		file.seekg(0, file.end);
		int lenght = file.tellg();
		file.seekg(0, file.beg);
		char* buffer = new char[lenght];
		memset(buffer, 0, lenght);
		file.read(buffer, lenght);
		file.close();
		
		std::string result(buffer);
		delete buffer;
		return result;
	}

//Timer CLASS
std::unique_ptr<Timer> Timer::m_Instance(nullptr);

Timer::Timer()
	: m_DeltaTime(0.0f), m_Frames(0), m_FrameCount(0)
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	m_Frequency = freq.QuadPart;
	QueryPerformanceCounter(&m_LastTime);
	m_CurrentTime.QuadPart = 0;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter(&m_CurrentTime);
	m_DeltaTime = (m_CurrentTime.QuadPart - m_LastTime.QuadPart) / m_Frequency;
	m_LastTime.QuadPart = m_CurrentTime.QuadPart;
}

float Timer::GetDeltaTime() const
{
	return m_DeltaTime;
}

void Timer::GetFrameCount(Window& window)
{
	m_FrameCount += m_DeltaTime;
	m_Frames++;	
	if(m_FrameCount > 1.0f)
	{
		std::stringstream Titel;
		Titel << window.GetTitel() << " | " << m_Frames << " fps";
		glfwSetWindowTitle(window.GetWindow(), Titel.str().c_str());
		m_Frames = 0;
		m_FrameCount -= 1.0f;
	}	
}

Timer& Timer::GetInstance()
{
	if(m_Instance == nullptr)
	{
		m_Instance.reset(new Timer());
		return *m_Instance;
	}

	return *m_Instance;
}

//End Timer CLASS
}
