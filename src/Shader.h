#pragma once
#include "EngineUtils.h"
#include <glad/glad.h>
#include <glm/glm/mat4x4.hpp>
#include <glm/glm/vec2.hpp>
#include <glm/glm/vec3.hpp>
#include <glm/glm/vec4.hpp>

#include <glm/glm/gtc/matrix_transform.hpp>
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
	
	GLint GetUniformLocation(const GLchar* name);

	void SetUniformMat4f(const GLchar* name, const glm::mat4 matrix);
	void SetUniform1f(const GLchar* name, float value);
	void SetUniform2f(const GLchar* name, const glm::vec2 vector);
	void SetUniform3f(const GLchar* name, const glm::vec3 vector);
	void SetUniform4f(const GLchar* name, const glm::vec4 vector);
	void SetUniform1i(const GLchar* name, int value);
};

}
