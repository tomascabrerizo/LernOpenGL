#pragma once 
#include "Renderable2D.h"
#include <vector>

namespace GameEngine {

class Group : public Renderable2D
{

private:
	std::vector<Renderable2D*> m_Renderables;
	glm::mat4 m_TransformationMatrix;
public:
	Group(const glm::mat4& matrix);
	~Group();
	void Add(Renderable2D* renderable);
	virtual void Submit(Renderer2D* render) override;
};

}
