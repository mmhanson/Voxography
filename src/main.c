#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "util.h"
#include "matrix.h"

#define WIDTH 1024
#define HEIGHT 768
#define MIN_MAJOR_VERSION 3
#define MIN_MINOR_VERSION 3

#define FOV ((PI) * 0.25f)
#define BLOCK_VERTEX_SHADER_PATH "shaders/vertex_shader.glsl"
#define BLOCK_FRAGMENT_SHADER_PATH "shaders/fragment_shader.glsl"
#define MATRIX_SHADER_NAME "MVP"
// 12 triangles, 3 vtxs each -> 36 vtxs
#define VTXS_PER_BLOCK 36

#define COPY_VERTEX(p, vertex_data);             \
    vertex_data[0] = p[0];                      \
    vertex_data[1] = p[1];                      \
    vertex_data[2] = p[2];                      \
    vertex_data = vertex_data + 3;

/*
 * Update the camera's position based on by current input.
 *
 * @p: point to array of the current x, y, z of the camera. Will be updated.
 * @rx @ry: point to the current rx, ry of camera. Will be updated.
 */
void update_camera(float* p, float* rx, float* ry);
/*
 * Initialize GLFW, create the window (@w), and initialize GLEW.
 */
void init_opengl();
/*
 * Compute the vertices for the triangles of a block.
 *
 * @a: array of 3 ints, position of vertex of the block most in the
 *   z- direction, the y+ direction, and x- direction. Its the topmost,
 *   northwest vtx of the block.
 * @vertex_data: array of 108 floats. Will contain triangle vertices.
 */
void comp_block_vertex_data(const int* a, float* vertex_data);

GLFWwindow* w;

int main()
{
    static GLfloat vertex_data[108]; // array of vtxs for one block
    const int block_coord[3] = {0, 0, 0};
    GLuint vertex_array;
    GLuint block_shaders_id;
    GLuint vertex_buffer_id;
    GLuint color_buffer_id;
    GLuint matrix_id;

    // camera information
    float matrix[16];
    float cam_p[3] = {0.0f, 0.0f, 2.0f};
    float cam_rx = 0.0f;
    float cam_ry = 0.0f;
    int rad = 40;

    init_opengl();

    comp_block_vertex_data(block_coord, vertex_data);
    // One color for each vertex. They were generated randomly.
    static const GLfloat color_data[] = {
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

    // create VAO
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    // give vertex data to opengl
    glGenBuffers(1, &vertex_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data),
                 vertex_data, GL_STATIC_DRAW);

    // give color data to opengl
    glGenBuffers(1, &color_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color_data),
                 color_data, GL_STATIC_DRAW);

    // load/ues shaders
    block_shaders_id = load_program(BLOCK_VERTEX_SHADER_PATH,
                                    BLOCK_FRAGMENT_SHADER_PATH);
    glUseProgram(block_shaders_id);
    matrix_id = glGetUniformLocation(block_shaders_id, MATRIX_SHADER_NAME);

    // gameloop
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // UPDATE THE CAMERA //
        update_camera(cam_p, &cam_rx, &cam_ry);
        set_matrix_3d(matrix, WIDTH, HEIGHT, cam_p[0], cam_p[1], cam_p[2],
                      cam_rx, cam_ry, FOV, 0, rad);
        glUniformMatrix4fv(matrix_id, 1, GL_FALSE, matrix);

        // === draw triangle === 
        // 1st attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
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
        glBindBuffer(GL_ARRAY_BUFFER, color_buffer_id);
        glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
            );
        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, VTXS_PER_BLOCK);
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(w);
        glfwPollEvents();
    }
    while (glfwGetKey(w, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(w) == 0);
}

void update_camera(float* p, float* rx, float* ry)
{
    static float prev_time = 0.0f;
    static float f[3] = {0, 0, -1}; // points into screen
    static float r[3] = {1, 0, 0}; // points to the right of the screen
    float tmp[3];
    const float mouse_speed = 0.1f; // how fast camera rotates
    const float walk_speed = 1.0f; // how fast camera translates
    float current_time;
    float delta_x;
    float delta_y;
    float delta_t;
    double mouse_x;
    double mouse_y;

    glfwGetCursorPos(w, &mouse_x, &mouse_y);
    glfwSetCursorPos(w, WIDTH / 2, HEIGHT / 2);
    delta_x = (float)mouse_x - (WIDTH / 2);
    delta_y = (HEIGHT / 2) - (float)mouse_y;
    current_time = (float)glfwGetTime();
    delta_t = current_time - prev_time;
    prev_time = current_time;

    // UPDATE POSN //
    if (glfwGetKey(w, GLFW_KEY_W) == GLFW_PRESS)
    {
        // p = p + (d * delta_t * speed)
        vec_multiply(tmp, delta_t * walk_speed, f);
        vec_add(p, p, tmp);
    }
    if (glfwGetKey(w, GLFW_KEY_A) == GLFW_PRESS)
    {
        // p = p - (r * delta_t * speed)
        vec_multiply(tmp, delta_t * walk_speed, r);
        vec_sub(p, p, tmp);
    }
    if (glfwGetKey(w, GLFW_KEY_S) == GLFW_PRESS)
    {
        // p = p - (d * delta_t * speed)
        vec_multiply(tmp, delta_t * walk_speed, f);
        vec_sub(p, p, tmp);
    }
    if (glfwGetKey(w, GLFW_KEY_D) == GLFW_PRESS)
    {
        // p = p + (r * delta_t * speed)
        vec_multiply(tmp, delta_t * walk_speed, r);
        vec_add(p, p, tmp);
    }

    // UPDATE LOOK DIRECTION //
    *rx += mouse_speed * delta_t * delta_x;
    *ry += mouse_speed * delta_t * delta_y;

    // UPDATE FORWARD VEC //
    f[0] = sinf(*rx);
    f[1] = sinf(*ry); // to make movement horizontal, set to 0
    f[2] = -1.0f * cosf(*rx);
    normalize(&f[0], &f[1], &f[2]);

    // UPDATE RIGHT VEC //
    r[0] = sinf(*rx + (PI  * 0.5));
    r[1] = 0.0f;
    r[2] = -1.0f * cosf(*rx + (PI * 0.5));
    normalize(&r[0], &r[1], &r[2]);
}

void init_opengl()
{
    // initialize glfw
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize glfw.\n");
        exit(-1);
    }

    // minimum versions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MIN_MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MIN_MINOR_VERSION);

    // create window
    w = glfwCreateWindow(WIDTH, HEIGHT, "My Window", 0, 0);
    if (!w)
    {
        fprintf(stderr, "Failed to create window.\n");
        exit(-1);
    }
    glfwMakeContextCurrent(w);
    glfwSetCursorPos(w, WIDTH / 2, HEIGHT / 2); // place cursor at center

    // initialize glew
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize glew.\n");
        exit(-1);
    }

    // enable occlusion
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetInputMode(w, GLFW_STICKY_KEYS, GL_TRUE);
}

void comp_block_vertex_data(const int* a, float* vertex_data)
{
    // TODO use VBO indexing
    // see notebook p.79 for drawings. Transfer in when finalized.
    const int vertex_data_size = 108;
    const int b[3] = {a[0]+1, a[1]  , a[2]  };
    const int c[3] = {a[0]  , a[1]  , a[2]+1};
    const int d[3] = {a[0]+1, a[1]  , a[2]+1};
    const int e[3] = {a[0]  , a[1]-1, a[2]  };
    const int f[3] = {a[0]+1, a[1]-1, a[2]  };
    const int g[3] = {a[0]  , a[1]-1, a[2]+1};
    const int h[3] = {a[0]+1, a[1]-1, a[2]+1};

    // face 1
    COPY_VERTEX(a, vertex_data); // a-b-e
    COPY_VERTEX(b, vertex_data);
    COPY_VERTEX(e, vertex_data);
    COPY_VERTEX(e, vertex_data); // e-f-b
    COPY_VERTEX(f, vertex_data);
    COPY_VERTEX(b, vertex_data);
    // face 2
    COPY_VERTEX(a, vertex_data); // a-c-e
    COPY_VERTEX(c, vertex_data);
    COPY_VERTEX(e, vertex_data);
    COPY_VERTEX(e, vertex_data); // e-g-c
    COPY_VERTEX(g, vertex_data);
    COPY_VERTEX(c, vertex_data);
    // face 3
    COPY_VERTEX(c, vertex_data); // c-d-g
    COPY_VERTEX(d, vertex_data);
    COPY_VERTEX(g, vertex_data);
    COPY_VERTEX(g, vertex_data); // g-h-d
    COPY_VERTEX(h, vertex_data);
    COPY_VERTEX(d, vertex_data);
    // face 4
    COPY_VERTEX(b, vertex_data); // b-d-h
    COPY_VERTEX(d, vertex_data);
    COPY_VERTEX(h, vertex_data);
    COPY_VERTEX(f, vertex_data); // f-h-b
    COPY_VERTEX(h, vertex_data);
    COPY_VERTEX(b, vertex_data);
    // face 5
    COPY_VERTEX(a, vertex_data); // a-c-b
    COPY_VERTEX(c, vertex_data);
    COPY_VERTEX(b, vertex_data);
    COPY_VERTEX(b, vertex_data); // b-d-c
    COPY_VERTEX(d, vertex_data);
    COPY_VERTEX(c, vertex_data);
    // face 6
    COPY_VERTEX(e, vertex_data); // e-f-g
    COPY_VERTEX(f, vertex_data);
    COPY_VERTEX(g, vertex_data);
    COPY_VERTEX(g, vertex_data); // g-f-h
    COPY_VERTEX(f, vertex_data);
    COPY_VERTEX(h, vertex_data);
}
