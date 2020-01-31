#pragma once
#include <glad/glad.h>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/vec2.hpp>
#include <glm/glm/vec3.hpp>
#include <glm/glm/vec4.hpp>

#include "Renderable2D.h"

namespace GameEngine {

class Renderer2D
{
public:
	
	virtual ~Renderer2D(){};	
	virtual void Begin(){};
	virtual void End(){};
	virtual void Submit(Renderable2D* renderable) = 0;
	virtual void Flush() = 0;
};

}
