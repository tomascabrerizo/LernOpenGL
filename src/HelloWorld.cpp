#include "HelloWorld.h"
#include <iostream>

HelloWorld::HelloWorld(const char* text)
{
	m_Text = text;
}

void HelloWorld::Speak()
{
	std::cout << m_Text << std::endl; 
}
