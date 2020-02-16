This project started as my final project for my computer graphics class, but
I kept it going as a side-project in my free time. The goal is to make this
into a fully-featured voxel engine to play around with procedural terrain
and structure generation.

All graphics programming is done in OpenGL and everything else is programmed
in C.

## Dependencies
This program only depends on GLEW and GLFW and OpenGL drivers.
To install (tested on Ubuntu 18.04):

`sudo apt-get install -y libglew-dev libglfw3-dev xorg-dev`


## Credits
### Textures
Credit for textures go to: fogleman's Craft (https://github.com/fogleman/Craft),
the OCD texture pack for minecraft
(https://www.planetminecraft.com/texture_pack/ocd-pack/), and the plastic
texture pack for minecraft xbox-360
(https://marketplace.xbox.com/en-US/Product/Minecraft-Plastic-Texture-Pack/81834c2c-9a04-4bdb-adc5-4d8399e99bc7).
All textures included in this repository were created by myself, but I used the
texture atlas created in fogleman's Craft, and I drew heavy inspiration from the
OCD and pastic texture packs referenced above.

### Matrix Math
Credit goes to fogleman's Craft (https://github.com/fogleman/Craft) for
inspiration on how to handle the matrix math involved in the graphics side
of this project.
