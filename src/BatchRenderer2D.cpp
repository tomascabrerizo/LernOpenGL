#include "BatchRenderer2D.h"

namespace GameEngine {

BatchRenderer2D::BatchRenderer2D()
{
	Init();
}

BatchRenderer2D::~BatchRenderer2D()
{
	delete m_IBO;
}

void BatchRenderer2D::Init()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(RENDERER_VERTEX_INDEX);
	glEnableVertexAttribArray(RENDERER_COLOR_INDEX);
		glVertexAttribPointer(RENDERER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)0);
	glVertexAttribPointer(RENDERER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)(3 * sizeof(GLfloat)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLushort indices[RENDERER_INDEX_SIZE];
	GLuint offset = 0;
	for(int i = 0; i < RENDERER_INDEX_SIZE; i+=6)
	{
		indices[i + 0] = 0 + offset;
		indices[i + 1] = 1 + offset;
		indices[i + 2] = 2 + offset;
		indices[i + 3] = 2 + offset;
		indices[i + 4] = 3 + offset;
		indices[i + 5] = 0 + offset;

		offset += 4;
	}

	m_IBO = new IndexBuffer(indices, RENDERER_INDEX_SIZE);

	glBindVertexArray(0);
}

void BatchRenderer2D::Begin()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	m_VertexData = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void BatchRenderer2D::End()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BatchRenderer2D::Submit(Renderable2D* renderable)
{
	const glm::vec3& position = renderable->GetPosition();
	const glm::vec2& size = renderable->GetSize();
	const glm::vec4 color = renderable->GetColor();

	m_VertexData->Position = position;
	m_VertexData->Color = color;
	m_VertexData++;

	m_VertexData->Position = glm::vec3(position.x, position.y + size.y, position.z);
	m_VertexData->Color = color;
	m_VertexData++;
	
	m_VertexData->Position = glm::vec3(position.x + size.x, position.y + size.y, position.z);
	m_VertexData->Color = color;
	m_VertexData++;

	m_VertexData->Position = glm::vec3(position.x + size.x, position.y, position.z);
	m_VertexData->Color = color;
	m_VertexData++;

	m_IndexCount += 6;

}

void BatchRenderer2D::Flush()
{
	glBindVertexArray(m_VAO);
	m_IBO->Bind();
	glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);	
	m_IBO->Unbind();
	glBindVertexArray(0);
	m_IndexCount = 0;

}

}
