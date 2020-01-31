#pragma once
#include <string>
#include <fstream>
#include <cstring>
#include <memory>
#include <Windows.h>

//Utils functions like read flis, random number or timer
namespace GameEngine {

class Window;

	//Function to read text files
	std::string Read_File(const char* filepath);

	//Timer Class
	class Timer
	{
	private:
		float m_Frequency;
		LARGE_INTEGER m_LastTime;
		LARGE_INTEGER m_CurrentTime;
		float m_DeltaTime;

		unsigned int m_Frames;
		float m_FrameCount;
		
		static std::unique_ptr<Timer> m_Instance;
		Timer();

	public:
		~Timer();
		void Update();
		float GetDeltaTime() const;
		void GetFrameCount(Window& window);
		static Timer& GetInstance();
	};

}
