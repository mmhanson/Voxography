#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "util.h"
#include "matrix.h"

#define WIDTH 1024
#define HEIGHT 768

/*
 * Update the camera's position based on by current input.
 *
 * @x @y @z: point to the current x, y, z of the camera. Will be updated.
 * @rx @ry: point to the current rx, ry of camera. Will be updated.
 */
void update_camera(float* x, float* y, float* z, float* rx, float* ry);

GLFWwindow* w;

int main()
{
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
    w = glfwCreateWindow(WIDTH, HEIGHT, "My Window", 0, 0);
    if (!w)
    {
        fprintf(stderr, "Failed to create window.\n");
        return -1;
    }
    glfwMakeContextCurrent(w);

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
    /*
    // triangle
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
    */
    // cube
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    };
    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data[] = {
        0.583f,  0.771f,  0.014f,
        0.609f,  0.115f,  0.436f,
        0.327f,  0.483f,  0.844f,
        0.822f,  0.569f,  0.201f,
        0.435f,  0.602f,  0.223f,
        0.310f,  0.747f,  0.185f,
        0.597f,  0.770f,  0.761f,
        0.559f,  0.436f,  0.730f,
        0.359f,  0.583f,  0.152f,
        0.483f,  0.596f,  0.789f,
        0.559f,  0.861f,  0.639f,
        0.195f,  0.548f,  0.859f,
        0.014f,  0.184f,  0.576f,
        0.771f,  0.328f,  0.970f,
        0.406f,  0.615f,  0.116f,
        0.676f,  0.977f,  0.133f,
        0.971f,  0.572f,  0.833f,
        0.140f,  0.616f,  0.489f,
        0.997f,  0.513f,  0.064f,
        0.945f,  0.719f,  0.592f,
        0.543f,  0.021f,  0.978f,
        0.279f,  0.317f,  0.505f,
        0.167f,  0.620f,  0.077f,
        0.347f,  0.857f,  0.137f,
        0.055f,  0.953f,  0.042f,
        0.714f,  0.505f,  0.345f,
        0.783f,  0.290f,  0.734f,
        0.722f,  0.645f,  0.174f,
        0.302f,  0.455f,  0.848f,
        0.225f,  0.587f,  0.040f,
        0.517f,  0.713f,  0.338f,
        0.053f,  0.959f,  0.120f,
        0.393f,  0.621f,  0.362f,
        0.673f,  0.211f,  0.457f,
        0.820f,  0.883f,  0.371f,
        0.982f,  0.099f,  0.879f
    };

    // load the vertex data
    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // load the color data
    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    // LOAD SHADERS //
    GLuint programID = load_program("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");

    // MAKE MVP MATRIX //
    float mvp_matrix[16];
    float cam_x = 5.0;
    float cam_y = 2.0;
    float cam_z = 3;
    float cam_rx = PI * -0.3f;
    float cam_ry = PI * -0.1f;
    float fov = PI * 0.25f; // 45 degree FOV
    int rad = 40;

    // use shaders
    glUseProgram(programID);
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // gameloop
    glfwSetInputMode(w, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // UPDATE THE CAMERA //
        update_camera(&cam_x, &cam_y, &cam_z, &cam_rx, &cam_ry);
        set_matrix_3d(mvp_matrix, WIDTH, HEIGHT, cam_x, cam_y, cam_z,
                      cam_rx, cam_ry, fov, 0, rad);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, mvp_matrix);

        // === draw triangle === 
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
        // 2nd attribute buffer : colors
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
            );
        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12 triangles, 3 vtxs ea
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }
    while (glfwGetKey(w, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(w) == 0);
}

void update_camera(float* x, float* y, float* z, float* rx, float* ry)
{
    static float prev_time = 0.0f;
    const float mouse_speed = 0.1f; // how fast camera rotates
    float current_time;
    float delta_x;
    float delta_y;
    float delta_t;
    double mouse_x;
    double mouse_y;

    glfwGetCursorPos(w, &mouse_x, &mouse_y);
    glfwSetCursorPos(w, WIDTH / 2, HEIGHT / 2);
    delta_x = (WIDTH / 2) - (float)mouse_x;
    delta_y = (HEIGHT / 2) - (float)mouse_y;
    current_time = (float)glfwGetTime();
    delta_t = current_time - prev_time;
    prev_time = current_time;

    *rx += mouse_speed * delta_t * delta_x;
    *ry += mouse_speed * delta_t * delta_y;
}














