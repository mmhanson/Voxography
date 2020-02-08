#version 330 core

// texture logic
layout (location = 0) in vec4 position;
layout (location = 1) in vec2 texcoord;
varying vec2 fragment_texcoord;

// color logic
// in vec4 position;
// in vec3 vertexColor;
// out vec3 fragmentColor;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * position;

    // color logic
    //fragmentColor = vertexColor ;

    // texture logic
    fragment_texcoord = texcoord;
}
