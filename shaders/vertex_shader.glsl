#version 330 core
//layout(location=0) in vec3 vertexPosition_modelspace;
layout(location=0) in vec4 position;

uniform mat4 MVP;

void main()
{
    //gl_Position.xyz = vertexPosition_modelspace;
    //gl_Position.w = 1.0;
    //gl_Position = position;
    gl_Position = MVP * position;
    //gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
}