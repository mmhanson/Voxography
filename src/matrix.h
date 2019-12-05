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
 *
 * Translates vertices @dx units to the right, @dy units up, and
 * @dz units [out of the screen?].
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
 *
 * @fov: field of view in radians.
 * @aspect: aspect ratio of window
 * @near @far: render objects in (@near->@far], in camera-coord units.
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
 * Note: width and height are combined to make the aspect ratio:
 * `aspect = width/height`. Using the width/height of the window in pixels will
 * work, but you can also use any other equivalent ratio.
 *
 * @width: width of the window in pixels.
 * @height: height of the window in pixels.
 * @x: x of camera. (in camera-coord units).
 * @y: y of camera. (in camera-coord units).
 * @z: z of camera. (in camera-coord units).
 * @rx: rotation in x direction of camera. Rotates the camera left in radians.
 * @ry: rotation in y direction of camera. Rotates the camera up in radians.
 * @fov: (whole) field of view. In radians.
 * @ortho: orthogonal projection (1) or perspective projection (0).
 * @radius: render radius. How far from camera to render (in camera-coord units).
 *   display region will be (0.125->radius].
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
