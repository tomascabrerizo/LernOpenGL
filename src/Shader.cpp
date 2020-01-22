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

}
