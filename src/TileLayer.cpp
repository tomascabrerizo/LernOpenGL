#include "TileLayer.h"
#include "BatchRenderer2D.h"

namespace GameEngine {

TileLayer::TileLayer(Shader* shader)
	: Layer(new BatchRenderer2D(), shader, glm::ortho(0.0f, 16.0f, 9.0f, 0.0f, -1.0f, 1.0f)) 
{

}	

}
