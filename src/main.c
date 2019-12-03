#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "util.h"
#include "matrix.h"

#define WIDTH 1024
#define HEIGHT 768

int main()
{
    GLFWwindow* window;
    GLuint VertexArrayID;

    // initialize glfw
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize glfw.\n");
        return -1;
    }

    // minimum versions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // create window
    window = glfwCreateWindow(WIDTH, HEIGHT, "My Window", 0, 0);
    if (!window)
    {
        fprintf(stderr, "Failed to create window.\n");
        return -1;
    }
    glfwMakeContextCurrent(window);

    // initialize glew
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize glew.\n");
        return -1;
    }

    // === triangle stuff ===
    // create triangle VAO (vtx array obj)
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // LOAD SHADERS //
    GLuint programID = load_program("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");

    // MAKE MVP MATRIX //
    float mvp_matrix[16];
    float cam_x = 4;
    float cam_y = 3;
    float cam_z = 3;
    float cam_rx = 0;
    float cam_ry = 0;
    float fov = 45.0f; // radians?
    int rad = 120;
    set_matrix_3d(mvp_matrix, WIDTH, HEIGHT, cam_x, cam_y, cam_z,
                  cam_rx, cam_ry, fov, 0, rad);
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    // gameloop
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // === draw triangle === 
        // use shaders
        glUseProgram(programID);
        // 1st attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
            );
        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);
}
