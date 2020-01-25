#pragma once

#include <glm/glm/vec2.hpp>
#include <glm/glm/vec3.hpp>
#include <glm/glm/vec4.hpp>
#include "Shader.h"

namespace GameEngine {

struct VertexData
{
	glm::vec3 Position; //3*4 = 12 bytes
	glm::vec4 Color;    //4*4 = 16 bytes
	//----------------------- = 28 bytes
};

class Renderable2D
{
protected:
	glm::vec3 m_Position;
	glm::vec2 m_Size;
	glm::vec4 m_Color;

	
public:

	Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color);
	~Renderable2D();
	
	const glm::vec3 GetPosition() const;
	const glm::vec2 GetSize() const;
	const glm::vec4 GetColor() const;

};

}
