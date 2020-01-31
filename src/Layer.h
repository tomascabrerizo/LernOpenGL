#pragma once
#include "Shader.h"
#include "Renderer2D.h"
#include "Renderer2D.h"
#include <vector>

namespace GameEngine {

class Layer
{

protected:
	Renderer2D* m_Renderer;
	Shader* m_Shader;
	glm::mat4 m_Projection;

	std::vector<Renderable2D*>m_Renderables;

	Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projection);

public:
	virtual ~Layer();
	virtual void Add(Renderable2D* renderable);
	virtual void Render();	
};

}
