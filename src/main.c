#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "util.h"
#include "matrix.h"
#include "../deps/lodepng/lodepng.h"

#define WIDTH 1024
#define HEIGHT 768
#define MIN_MAJOR_VERSION 3
#define MIN_MINOR_VERSION 3

#define FOV ((PI) * 0.25f)
#define BLOCK_VERTEX_SHADER_PATH "shaders/vertex_shader.glsl"
#define BLOCK_FRAGMENT_SHADER_PATH "shaders/fragment_shader.glsl"
#define MATRIX_SHADER_NAME "MVP"
#define TEXTURE_ATLAS_PATH "./assets/textures/texture_atlas.png"
// 12 triangles, 3 vtxs each -> 36 vtxs
#define VTXS_PER_BLOCK 36

#define COPY_VERTEX(v, vertices);            \
    vertices[0] = v[0];                      \
    vertices[1] = v[1];                      \
    vertices[2] = v[2];                      \
    vertices = vertices + 3;

#define COPY_TEXCOORD(t, texcoords); \
    texcoords[0] = t[0];             \
    texcoords[1] = t[1];             \
    texcoords = texcoords + 2;


typedef struct BlockTag
{
    GLuint VAO_id;
    GLuint VBO_id;
    GLuint texcoords_buffer_id;
    GLfloat* vertices; // array of 108 floats (36 points)
    GLfloat* texcoords; // texture (u,v) coordinates into texture atlas
    size_t vertices_size;
    size_t texcoords_size;
} Block;

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

/*
 * Compute the texcoords for a voxel.
 *
 * @texture_data: array of 72 floats (36 texcoords). Will contain texcoords.
 */
void comp_block_texture_data(float* texture_data);

/*
 * Construct a block object.
 *
 * @x, @y, @z: create coordinate of corner most in the z-, y+, x- direction.
 *   designate 'corner a' of the block.
 */
Block* construct_block(int x, int y, int z);

GLFWwindow* w;
GLint texcoord_attrib_idx;
GLint position_attrib_idx;

int main()
{
    GLuint block_shaders_id;
    GLuint matrix_id;
    Block* blocks[7]; // NULL-term'd array of pointers to each block
    Block* block_cursor;
    int idx;

    // textures
    int error;
    unsigned char* atlas_image;
    unsigned int width;
    unsigned int height;
    GLuint texture_atlas_id;

    // camera information
    float matrix[16];
    float cam_p[3] = {-1.0f, 1.5f, 2.0f};
    float cam_rx = 0.5f;
    float cam_ry = -0.8f;
    int rad = 40;

    init_opengl();

    // load/use shaders
    block_shaders_id = load_program(BLOCK_VERTEX_SHADER_PATH,
                                    BLOCK_FRAGMENT_SHADER_PATH);
    glUseProgram(block_shaders_id);
    matrix_id = glGetUniformLocation(block_shaders_id, MATRIX_SHADER_NAME);

    // bind shader inputs
    texcoord_attrib_idx = glGetAttribLocation(block_shaders_id, "texcoord");
    if (texcoord_attrib_idx == -1)
    {
        fprintf(stderr, "Could not bind attribute 'texcoord'.\n");
    }
    position_attrib_idx = glGetAttribLocation(block_shaders_id, "position");
    if (position_attrib_idx == -1)
    {
        fprintf(stderr, "Couldn't bind attrib 'position' to shaders.\n");
    }

    // put in array
    blocks[0] = construct_block(0, 0, 0);
    blocks[1] = construct_block(1, 0, 0);
    blocks[2] = construct_block(0, 0, -1);
    blocks[3] = construct_block(0, 0, 1);
    blocks[4] = construct_block(-1, 0, 0);
    blocks[5] = construct_block(0, 1, 0);
    blocks[6] = NULL;

    // load texture atlas into memory
    error = lodepng_decode32_file(&atlas_image, &width, &height, TEXTURE_ATLAS_PATH);
    if (error)
    {
        fprintf(stderr, "Could not load texture at '%s', error %u: %s\n",
                TEXTURE_ATLAS_PATH, error, lodepng_error_text(error));
        return 1;
    }

    // load texture atlas into GPU buffer
    glGenTextures(1, &texture_atlas_id);
    glBindTexture(GL_TEXTURE_2D, texture_atlas_id);
    glActiveTexture(GL_TEXTURE0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, atlas_image);
    free(atlas_image);

    // gameloop
    while (glfwGetKey(w, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(w) == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // UPDATE THE CAMERA //
        update_camera(cam_p, &cam_rx, &cam_ry);
        set_matrix_3d(matrix, WIDTH, HEIGHT, cam_p[0], cam_p[1], cam_p[2],
                      cam_rx, cam_ry, FOV, 0, rad);
        glUniformMatrix4fv(matrix_id, 1, GL_FALSE, matrix);

        // DRAW EACH BLOCK //
        for (idx = 0; blocks[idx] != NULL; idx++)
        {
            block_cursor = blocks[idx];

            // draw the block
            glBindVertexArray(block_cursor->VAO_id);
            glEnableVertexAttribArray(position_attrib_idx); // enable the new VAO attribute
            glEnableVertexAttribArray(texcoord_attrib_idx); // enable the new VAO attribute
            glDrawArrays(GL_TRIANGLES, 0, VTXS_PER_BLOCK);
            glBindVertexArray(0);
            glDisableVertexAttribArray(0);
        }

        glfwSwapBuffers(w);
        glfwPollEvents();
    }
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

    // enable z-buffering
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetInputMode(w, GLFW_STICKY_KEYS, GL_TRUE);
}

void comp_block_vertex_data(const int* a, float* vertex_data)
{
    // TODO use VBO indexing
    // see project notebook p.9 for drawings. Transfer in when finalized.
    const int b[3] = {a[0]+1, a[1]  , a[2]  };
    const int c[3] = {a[0]  , a[1]  , a[2]+1};
    const int d[3] = {a[0]+1, a[1]  , a[2]+1};
    const int e[3] = {a[0]  , a[1]-1, a[2]  };
    const int f[3] = {a[0]+1, a[1]-1, a[2]  };
    const int g[3] = {a[0]  , a[1]-1, a[2]+1};
    const int h[3] = {a[0]+1, a[1]-1, a[2]+1};

    // face 1
    COPY_VERTEX(b, vertex_data); // b-a-f
    COPY_VERTEX(a, vertex_data);
    COPY_VERTEX(f, vertex_data);
    COPY_VERTEX(e, vertex_data); // e-f-a
    COPY_VERTEX(f, vertex_data);
    COPY_VERTEX(a, vertex_data);
    // face 2
    COPY_VERTEX(a, vertex_data); // a-c-e
    COPY_VERTEX(c, vertex_data);
    COPY_VERTEX(e, vertex_data);
    COPY_VERTEX(g, vertex_data); // g-e-c
    COPY_VERTEX(e, vertex_data);
    COPY_VERTEX(c, vertex_data);
    // face 3
    COPY_VERTEX(c, vertex_data); // c-d-g
    COPY_VERTEX(d, vertex_data);
    COPY_VERTEX(g, vertex_data);
    COPY_VERTEX(h, vertex_data); // h-g-d
    COPY_VERTEX(g, vertex_data);
    COPY_VERTEX(d, vertex_data);
    // face 4
    COPY_VERTEX(d, vertex_data); // d-b-h
    COPY_VERTEX(b, vertex_data);
    COPY_VERTEX(h, vertex_data);
    COPY_VERTEX(f, vertex_data); // f-h-b
    COPY_VERTEX(h, vertex_data);
    COPY_VERTEX(b, vertex_data);
    // face 5
    COPY_VERTEX(a, vertex_data); // a-b-c
    COPY_VERTEX(b, vertex_data);
    COPY_VERTEX(c, vertex_data);
    COPY_VERTEX(d, vertex_data); // d-c-b
    COPY_VERTEX(c, vertex_data);
    COPY_VERTEX(b, vertex_data);
    // face 6
    COPY_VERTEX(e, vertex_data); // e-f-g
    COPY_VERTEX(f, vertex_data);
    COPY_VERTEX(g, vertex_data);
    COPY_VERTEX(g, vertex_data); // g-h-f
    COPY_VERTEX(h, vertex_data);
    COPY_VERTEX(f, vertex_data);
}

void comp_block_texture_data(float* texture_data)
{
    // see projects notebook p.9 for drawings. Transfer in when finalized.
    const float a[2] = {0.0f, 0.8750f}; // topleft
    const float b[2] = {0.0625f, 0.8750f}; // topright
    const float c[2] = {0.0f, 0.9375f}; // bottomleft
    const float d[2] = {0.0625f, 0.9375f}; // bottomright

    COPY_TEXCOORD(a, texture_data);
    COPY_TEXCOORD(b, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(d, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(b, texture_data);

    COPY_TEXCOORD(a, texture_data);
    COPY_TEXCOORD(b, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(d, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(b, texture_data);

    COPY_TEXCOORD(a, texture_data);
    COPY_TEXCOORD(b, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(d, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(b, texture_data);

    COPY_TEXCOORD(a, texture_data);
    COPY_TEXCOORD(b, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(d, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(b, texture_data);

    COPY_TEXCOORD(a, texture_data);
    COPY_TEXCOORD(b, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(d, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(b, texture_data);

    COPY_TEXCOORD(a, texture_data);
    COPY_TEXCOORD(b, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(d, texture_data);
    COPY_TEXCOORD(c, texture_data);
    COPY_TEXCOORD(b, texture_data);
}

Block* construct_block(int x, int y, int z)
{
    const size_t vertex_data_size = 108 * sizeof(GLfloat);
    const size_t texture_data_size = 72 * sizeof(GLfloat);
    Block* new_block;
    int a[3];

    a[0] = x;
    a[1] = y;
    a[2] = z;

    new_block = malloc(sizeof(Block));
    new_block->vertices = malloc(vertex_data_size);
    new_block->vertices_size = vertex_data_size;
    new_block->texcoords = malloc(texture_data_size);
    new_block->texcoords_size = texture_data_size;

    comp_block_vertex_data(a, new_block->vertices);
    comp_block_texture_data(new_block->texcoords);

    glGenVertexArrays(1, &(new_block->VAO_id));
    glBindVertexArray(new_block->VAO_id);

    // buffer vertex data into block's VBO
    glGenBuffers(1, &new_block->VBO_id);
    glBindBuffer(GL_ARRAY_BUFFER, new_block->VBO_id);
    glBufferData(GL_ARRAY_BUFFER, new_block->vertices_size,
                 new_block->vertices, GL_STATIC_DRAW); // load block's vertices into block's VBO
    glVertexAttribPointer(position_attrib_idx, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // make VAO's 'position' attribute point to VBO above

    // buffer texture coordinates
    glGenBuffers(1, &new_block->texcoords_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, new_block->texcoords_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, new_block->texcoords_size,
                 new_block->texcoords, GL_STATIC_DRAW);
    glVertexAttribPointer(texcoord_attrib_idx, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(position_attrib_idx); // enable the new VAO attribute
    glEnableVertexAttribArray(texcoord_attrib_idx);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return new_block;
}
