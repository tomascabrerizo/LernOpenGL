#include "Shader.h"
#include <vector>
#include <iostream>

namespace GameEngine {

Shader::Shader(const char* vertPath, const char* fragPath)
	:m_VertPath(vertPath), m_FragPath(fragPath)
{
	m_ShaderID = LoadShader();
}

Shader::~Shader()
{
	glDeleteProgram(m_ShaderID);
}

GLuint Shader::LoadShader()
{
	GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
	
	std::string vertSrc = Read_File(m_VertPath);
	std::string fragSrc = Read_File(m_FragPath);
	
	const char* vertSrcChar = vertSrc.c_str();
	const char* fragSrcChar = fragSrc.c_str();

	glShaderSource(vertex, 1, & vertSrcChar, NULL);
	glShaderSource(fragment, 1, & fragSrcChar, NULL);

	glCompileShader(vertex);	
	/*Check if shader compilation succed*/
	GLint result;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
	if(result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(vertex, length, &length, &error[0]);
		std::cout << "Faild to Compile Vertex shader\n" << "Error: " << &error[0] << std::endl;
		glDeleteShader(vertex);
		return 0;
	}
	
	glCompileShader(fragment);	
	/*Check if shader compilation succed*/
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
	if(result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(fragment, length, &length, &error[0]);
		std::cout << "Faild to Compile Fragment shader\n" << "Error: " << &error[0] << std::endl;
		glDeleteShader(fragment);
		return 0;
	}	

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	
	glLinkProgram(program);
	glValidateProgram(program);
	
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

void Shader::Enable()
{
	glUseProgram(m_ShaderID);
}

void Shader::Disable()
{
	glUseProgram(0);
}

GLint Shader::GetUniformLocation(const GLchar* name)
{
	return glGetUniformLocation(m_ShaderID, name);
}

void Shader::SetUniformMat4f(const GLchar* name, const glm::mat4 matrix)	
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}
void Shader::SetUniform1f(const GLchar* name, float value)
{
	glUniform1f(GetUniformLocation(name),value);
}
void Shader::SetUniform2f(const GLchar* name, const glm::vec2 vector)
{
	glUniform2f(GetUniformLocation(name), vector.x, vector.y);
}
void Shader::SetUniform3f(const GLchar* name, const glm::vec3 vector)
{
	glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
}
void Shader::SetUniform4f(const GLchar* name, const glm::vec4 vector)
{
	glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}
void Shader::SetUniform1i(const GLchar* name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

}
