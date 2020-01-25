#include "Renderable2D.h"

namespace GameEngine {

Renderable2D::Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
	: m_Position(position), m_Size(size), m_Color(color)
{

}

Renderable2D::~Renderable2D()
{
}

const glm::vec3 Renderable2D::GetPosition() const
{
	return m_Position;
}

const glm::vec2 Renderable2D::GetSize() const
{
	return m_Size;
}

const glm::vec4 Renderable2D::GetColor() const
{
	return m_Color;
}




}
