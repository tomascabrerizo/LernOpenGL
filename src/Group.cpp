#include "Group.h"
#include "Renderer2D.h"

namespace GameEngine {

Group::Group(const glm::mat4& matrix)
	: m_TransformationMatrix(matrix)
{

}

Group::~Group()
{
	for(Renderable2D* renderable : m_Renderables)
		delete renderable;
}

void Group::Submit(Renderer2D* render)
{
	render->Push(m_TransformationMatrix);
	for(Renderable2D* renderable : m_Renderables)
		renderable->Submit(render);
	render->Pop();
}

void Group::Add(Renderable2D* renderable)
{
	m_Renderables.push_back(renderable);
}

}

