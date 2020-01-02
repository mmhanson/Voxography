#version 330 core
out vec3 color;
// interpolated values from vertex shader
in vec3 fragmentColor;

void main()
{
    // red
    //color = vec3(1,0,0);

    // output color->color specified in vtx shader interpolated
    // btwn 3 surrounding vtxs
    color = fragmentColor;
}