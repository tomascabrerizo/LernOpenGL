#pragma once
#include <glad/glad.h>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/vec2.hpp>
#include <glm/glm/vec3.hpp>
#include <glm/glm/vec4.hpp>
#include <vector>
#include "Renderable2D.h"


namespace GameEngine {

class Renderer2D
{
protected:
	std::vector<glm::mat4> m_TransformationStack;
	glm::mat4* m_TransformBack;

	Renderer2D() 
	{
		m_TransformationStack.push_back(glm::mat4(1.0f));
		m_TransformBack = &m_TransformationStack.back();
	}

public:	
	void Push(const glm::mat4& matrix, bool override = false)
	{
		if(override)
			m_TransformationStack.push_back(matrix);
		else
			m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
			
		m_TransformBack = &m_TransformationStack.back();
	}
	void Pop()
	{
		if(m_TransformationStack.size() > 1)
		{
			m_TransformationStack.pop_back();
			m_TransformBack = &m_TransformationStack.back();
		}
	}

	virtual ~Renderer2D(){};	
	virtual void Begin(){};
	virtual void End(){};
	virtual void Submit(Renderable2D* renderable) = 0;
	virtual void Flush() = 0;
};

}
