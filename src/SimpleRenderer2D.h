#pragma once
#include "Renderer2D.h"
#include <deque>
#include "StaticSprite.h"

namespace GameEngine {

class SimpleRenderer2D : public Renderer2D
{
private:
	std::deque<StaticSprite*> m_RenderQueue;
	
public:
	virtual void Submit(Renderable2D* renderable) override;
	virtual void Flush() override;

};

}
