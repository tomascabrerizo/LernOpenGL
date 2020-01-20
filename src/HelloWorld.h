#pragma once
#include <iostream>

class HelloWorld
{
private:
	const char* m_Text;
public:
	HelloWorld(const char* text);
	
	void Speak();
};
