#version 330 core

layout (location = 0) out vec4 color;

uniform vec2 light_pos;


in DATA
{
	vec4 pos;
	vec4 color;
} fs_in;


void main()
{
	float intensity = 1.0f / length(fs_in.pos.xy - light_pos);
	color = fs_in.color * intensity;
}