#include "Layer.h"

namespace GameEngine {

Layer::Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projection)
	: m_Renderer(renderer), m_Shader(shader), m_Projection(projection)
{
	shader->Enable();
	shader->SetUniformMat4f("pr_matrix", m_Projection);
	shader->Disable();
}

Layer::~Layer()
{
	delete m_Shader;
	delete m_Renderer;

	for(std::size_t i = 0; i < m_Renderables.size(); i++)
		delete m_Renderables[i];
}

void Layer::Add(Renderable2D* renderable)
{
	m_Renderables.push_back(renderable);
}

void Layer::Render()
{
	m_Shader->Enable();
	m_Renderer->Begin();
	
	for(Renderable2D* renderable : m_Renderables)
	{
		renderable->Submit(m_Renderer);
	}

	m_Renderer->Flush();

	m_Renderer->End();
	m_Shader->Disable();
}

}
