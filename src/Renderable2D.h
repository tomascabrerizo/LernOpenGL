#pragma once

#include <glm/glm/vec2.hpp>
#include <glm/glm/vec3.hpp>
#include <glm/glm/vec4.hpp>
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

namespace GameEngine {

class Renderable2D
{
protected:
	glm::vec2 m_Size;
	glm::vec3 m_Position;
	glm::vec4 m_Color;

	VertexArray* m_VertexArray;
	IndexBuffer* m_IndexBuffer;
	Shader& m_Shader;

public:

	Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader);
	~Renderable2D();
	
	const glm::vec3 GetPosition() const;
	const glm::vec2 GetSize() const;
	const glm::vec4 GetColor() const;

	const VertexArray* GetVAO() const;
	const IndexBuffer* GetIBO() const;
	Shader& GetShader() const;
};

}
