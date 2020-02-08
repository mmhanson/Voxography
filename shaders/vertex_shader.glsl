#version 330 core

// texture logic
in vec2 texcoord;
in vec4 position;
out vec2 fragment_texcoord;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * position;
    fragment_texcoord = texcoord;
}
