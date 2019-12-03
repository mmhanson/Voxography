/*
 * A set of functions to deal with 4x4 matrices of floats.
 *
 * Originally written by Fogleman (github.com/fogleman/craft).
 * Modified by Max Hanson, December 2019.
 */

#ifndef MATRIX_H
#define MATRIX_H


/*
 * Normalize a vector of three floats.
 */
void normalize(float *x, float *y, float *z);

/*
 * Create a 4x4 identity matrix.
 */
void mat_identity(float *matrix);

/*
 * Create a translation matrix.
 */
void mat_translate(float *matrix, float dx, float dy, float dz);

/*
 * Crate a rotation matrix.
 */
void mat_rotate(float *matrix, float x, float y, float z, float angle);

/*
 * Multiply a matrix by a vector.
 */
void mat_vec_multiply(float *vector, float *a, float *b);

/*
 * Multiply two matrices.
 */
void mat_multiply(float *matrix, float *a, float *b);

/*
 * ???
 */
void mat_apply(float *data, float *matrix, int count, int offset, int stride);

/*
 * ???
 */
void frustum_planes(float planes[6][4], int radius, float *matrix);

/*
 * ???
 */
void mat_frustum(
    float *matrix, float left, float right, float bottom,
    float top, float znear, float zfar);

/*
 * Create a perspective projection matrix.
 */
void mat_perspective(
    float *matrix, float fov, float aspect,
    float near, float far);

/*
 * Create an orthogonal projection matrix.
 */
void mat_ortho(
    float *matrix,
    float left, float right, float bottom, float top, float near, float far);

/*
 * Create a 2d MVP matrix.
 */
void set_matrix_2d(float *matrix, int width, int height);

/*
 * Create a 3d MVP matrix.
 *
 * @width: width of image plane to project onto.
 * @height: height of image plane to project onto.
 * @x: x of camera.
 * @y: y of camera.
 * @z: z of camera.
 * @rx: rotation in x direction of camera.
 * @ry: rotation in y direction of camera.
 * @fov: field of view.
 * @ortho: orthogonal projection (1) or perspective projection (0).
 * @radius: render radius. How far from camera to render.
 */
void set_matrix_3d(
    float *matrix, int width, int height,
    float x, float y, float z, float rx, float ry,
    float fov, int ortho, int radius);

/*
 * ???
 */
void set_matrix_item(float *matrix, int width, int height, int scale);


#endif
