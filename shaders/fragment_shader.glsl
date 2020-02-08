#version 330 core

// texture logic
in vec2 fragment_texcoord;
uniform sampler2D mytexture;
out vec3 color;

void main()
{
    color = texture2D(mytexture, fragment_texcoord).rgb; // TODO flip?
}
