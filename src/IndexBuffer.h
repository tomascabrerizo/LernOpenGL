#pragma once
#include <glad/glad.h>

namespace GameEngine {

class IndexBuffer
{
private:
	GLuint m_BufferID;
	GLuint m_Count;

public:
	IndexBuffer(GLushort* data, GLsizei cout);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	GLuint GetCount() const;
};	

}
