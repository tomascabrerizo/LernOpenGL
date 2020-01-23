#include "Renderable2D.h"

namespace GameEngine {

Renderable2D::Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader)
	: m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
{
	m_VertexArray = new VertexArray();

	GLfloat vertices[] = 
	{
		0.0f,     0.0f,     0.0f,
		0.0f,     m_Size.y, 0.0f,
		m_Size.x, m_Size.y, 0.0f,
		m_Size.x, 0.0f,     0.0f		
	};

	GLfloat colors[] =
	{
		m_Color.x, m_Color.y, m_Color.z, m_Color.w,
		m_Color.x, m_Color.y, m_Color.z, m_Color.w,
		m_Color.x, m_Color.y, m_Color.z, m_Color.w,
		m_Color.x, m_Color.y, m_Color.z, m_Color.w
	};
	
	m_VertexArray->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	m_VertexArray->AddBuffer(new Buffer(colors, 4 * 4, 4), 1);

	GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
	m_IndexBuffer = new IndexBuffer(indices, 6);
}

Renderable2D::~Renderable2D()
{
	delete m_VertexArray;
	delete m_IndexBuffer;
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

const VertexArray* Renderable2D::GetVAO() const
{
	return m_VertexArray;
}

const IndexBuffer* Renderable2D::GetIBO() const
{
	return m_IndexBuffer;
}

Shader& Renderable2D::GetShader() const
{
	return m_Shader;
}

}
