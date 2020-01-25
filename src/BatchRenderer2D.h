#pragma once

#include "Renderer2D.h"
#include "IndexBuffer.h"

namespace GameEngine {

#define RENDERER_MAX_SPRITES 20000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_MAX_SPRITES * RENDERER_SPRITE_SIZE
#define RENDERER_INDEX_SIZE RENDERER_MAX_SPRITES * 6

#define RENDERER_VERTEX_INDEX 0
#define RENDERER_COLOR_INDEX 1

class BatchRenderer2D : public Renderer2D
{
private:
	GLuint m_VAO;
	GLuint m_VBO;
	IndexBuffer* m_IBO;
	GLsizei m_IndexCount;
	VertexData* m_VertexData;

public:
	BatchRenderer2D();
	~BatchRenderer2D();
	void Init();
	virtual void Submit(Renderable2D* renderable) override;
	virtual void Flush() override;
	void Begin();
	void End();
};

}
