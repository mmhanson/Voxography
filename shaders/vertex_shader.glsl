#version 330 core

// texture logic
attribute vec4 position;
attribute vec2 texcoord;
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
