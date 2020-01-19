#version 330 core

// texture logic
// varying vec2 f_texcoord;
// uniform sampler2D mytexture;

// color logic
out vec3 color;
in vec3 fragmentColor;

void main()
{
    // color logic
    color = fragmentColor;

    // texture logic
    // color = texture2D(mytexture, f_texcoord).rgb // TODO flip?
}
