#version 330 core

layout(location = 0) out vec4 color;

uniform vec2 light_pos;

in vec4 pos;
in vec4 ml_color;

void main()
{
	float intensity = 1.0 / length(pos.xy - light_pos);
	color = ml_color * intensity;
}
