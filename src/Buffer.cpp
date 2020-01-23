#include "Buffer.h"

namespace GameEngine {

Buffer::Buffer(GLfloat* data, GLsizei cout, GLuint componentCount)
	:m_ComponentCout(componentCount)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, cout * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void Buffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint Buffer::GetComponentCount() const
{
	return m_ComponentCout;
}
}
