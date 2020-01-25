#include "SimpleRenderer2D.h"

namespace GameEngine {

void SimpleRenderer2D::Submit(Renderable2D* renderable)
{
	m_RenderQueue.push_back((StaticSprite*)renderable);
}

void SimpleRenderer2D::Flush()
{
	while(!m_RenderQueue.empty())
	{
		StaticSprite* renderable = m_RenderQueue.front();
		renderable->GetVAO()->Bind();
		renderable->GetIBO()->Bind();
		
		renderable->GetShader().SetUniformMat4f("ml_matrix", glm::translate(glm::mat4(1.0f), renderable->GetPosition()));	
		glDrawElements(GL_TRIANGLES, renderable->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, 0);

		renderable->GetVAO()->Unbind();
		renderable->GetIBO()->Unbind();	

		m_RenderQueue.pop_front();
	}
}

}
