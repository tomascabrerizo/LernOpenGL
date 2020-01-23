#version 330 core

layout (location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix;

out vec4 pos;
out vec4 ml_color;

void main()
{
	ml_color = color;
	pos = ml_matrix * position;
	gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
}
