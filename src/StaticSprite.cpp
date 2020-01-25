#include "StaticSprite.h"

namespace GameEngine {

StaticSprite::StaticSprite(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader) 
	: Renderable2D(position, size, color), m_Shader(shader)
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

StaticSprite::~StaticSprite() 
{
	delete m_VertexArray;
	delete m_IndexBuffer;
}

Shader& StaticSprite::GetShader() const
{
	return m_Shader;
}

const VertexArray* StaticSprite::GetVAO() const
{
	return m_VertexArray;
}

const IndexBuffer* StaticSprite::GetIBO() const
{
	return m_IndexBuffer;
}

}
