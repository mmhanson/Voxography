#version 330 core
//layout(location=0) in vec3 vertexPosition_modelspace;
layout(location=0) in vec4 position;

uniform mat4 MVP;

void main()
{
    //gl_Position = position;
    gl_Position = MVP * position;
}