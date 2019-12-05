#version 330 core
//layout(location=0) in vec3 vertexPosition_modelspace;
layout(location=0) in vec4 position;
layout(location = 1) in vec3 vertexColor;

out vec3 fragmentColor;

uniform mat4 MVP;

void main()
{
    //gl_Position = position;
    gl_Position = MVP * position;

    // color for ea vtx will be interpolated to prodcue the color
    // for each fragment
    fragmentColor = vertexColor ;
}