#pragma once
#include <glad/glad.h>

namespace GameEngine {
	
class Buffer 
{
private:
	GLuint m_BufferID;
	GLuint m_ComponentCout;

public:
	Buffer(GLfloat* data, GLsizei cout, GLuint componentCount);

	void Bind() const;
	void Unbind() const;
	GLuint GetComponentCount() const;
};

}
