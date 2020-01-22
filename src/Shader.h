#pragma once
#include "EngineUtils.h"
#include <glad/glad.h>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

namespace GameEngine {

class Shader
{
private:
	GLuint m_ShaderID;
	const char* m_VertPath;
	const char* m_FragPath;

	GLuint LoadShader();
public:
	Shader(const char* vertPath, const char* fragPath);
	~Shader();

	void Enable();
	void Disable();

	inline void SetUniformMat4f(glm::mat4 matrix)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, "pr_matrix"), 1, GL_FALSE, glm::value_ptr(matrix));
	}
};

}
