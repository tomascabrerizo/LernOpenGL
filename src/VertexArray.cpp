#include "VertexArray.h"

namespace GameEngine {

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_ArrayID);
}

VertexArray::~VertexArray()
{
	for(std::size_t i = 0; i < m_Buffers.size(); i++)
		delete m_Buffers[i];
	
	glDeleteVertexArrays(1, &m_ArrayID);
}

void VertexArray::AddBuffer(Buffer* buffer, GLuint index)
{
	m_Buffers.push_back(buffer);
	Bind();
	buffer->Bind();
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
	buffer->Unbind();
	Unbind();
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_ArrayID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

}
