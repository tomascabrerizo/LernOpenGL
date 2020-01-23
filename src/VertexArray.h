#pragma once
#include <glad/glad.h>
#include "Buffer.h"
#include <vector>

namespace GameEngine {

class VertexArray
{
private:
	GLuint m_ArrayID;
	std::vector<Buffer*> m_Buffers;

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(Buffer* buffer, GLuint index);
	void Bind() const;
	void Unbind() const;
};

}
