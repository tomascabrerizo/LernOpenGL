#pragma once

#include "Renderable2D.h"
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace GameEngine {

class StaticSprite : public Renderable2D
{
private:
	Shader& m_Shader;
	VertexArray* m_VertexArray;
	IndexBuffer* m_IndexBuffer;

public:
	StaticSprite(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader); 
	~StaticSprite();

	Shader& GetShader() const;
	const VertexArray* GetVAO() const;
	const IndexBuffer* GetIBO() const;

};

}
