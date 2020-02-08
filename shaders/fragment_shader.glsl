#version 330 core

// texture logic
varying vec2 fragment_texcoord;
uniform sampler2D mytexture;

// color logic
// out vec3 color;
// in vec3 fragmentColor;

void main()
{
    // color logic
    // color = fragmentColor;

    // texture logic
    color = texture2D(mytexture, fragment_texcoord).rgb // TODO flip?
}
