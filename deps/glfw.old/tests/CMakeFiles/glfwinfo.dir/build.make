# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/max/code/repos/Cubes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/max/code/repos/Cubes

# Include any dependencies generated for this target.
include deps/glfw/tests/CMakeFiles/glfwinfo.dir/depend.make

# Include the progress variables for this target.
include deps/glfw/tests/CMakeFiles/glfwinfo.dir/progress.make

# Include the compile flags for this target's objects.
include deps/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make

deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: deps/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: deps/glfw/tests/glfwinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/glfwinfo.c.o   -c /home/max/code/repos/Cubes/deps/glfw/tests/glfwinfo.c

deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/glfwinfo.c.i"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/code/repos/Cubes/deps/glfw/tests/glfwinfo.c > CMakeFiles/glfwinfo.dir/glfwinfo.c.i

deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/glfwinfo.c.s"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/code/repos/Cubes/deps/glfw/tests/glfwinfo.c -o CMakeFiles/glfwinfo.dir/glfwinfo.c.s

deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires:

.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires

deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides: deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires
	$(MAKE) -f deps/glfw/tests/CMakeFiles/glfwinfo.dir/build.make deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides.build
.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides

deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides.build: deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o


deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: deps/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: deps/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o   -c /home/max/code/repos/Cubes/deps/glfw/deps/getopt.c

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/code/repos/Cubes/deps/glfw/deps/getopt.c > CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/code/repos/Cubes/deps/glfw/deps/getopt.c -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires:

.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f deps/glfw/tests/CMakeFiles/glfwinfo.dir/build.make deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides.build
.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides.build: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o


deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: deps/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: deps/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o   -c /home/max/code/repos/Cubes/deps/glfw/deps/glad_gl.c

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/code/repos/Cubes/deps/glfw/deps/glad_gl.c > CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/code/repos/Cubes/deps/glfw/deps/glad_gl.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires:

.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires
	$(MAKE) -f deps/glfw/tests/CMakeFiles/glfwinfo.dir/build.make deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides.build
.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides.build: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o


deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: deps/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: deps/glfw/deps/glad_vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o   -c /home/max/code/repos/Cubes/deps/glfw/deps/glad_vulkan.c

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/code/repos/Cubes/deps/glfw/deps/glad_vulkan.c > CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/code/repos/Cubes/deps/glfw/deps/glad_vulkan.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires:

.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires
	$(MAKE) -f deps/glfw/tests/CMakeFiles/glfwinfo.dir/build.make deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides.build
.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides

deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides.build: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o


# Object files for target glfwinfo
glfwinfo_OBJECTS = \
"CMakeFiles/glfwinfo.dir/glfwinfo.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"

# External object files for target glfwinfo
glfwinfo_EXTERNAL_OBJECTS =

deps/glfw/tests/glfwinfo: deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o
deps/glfw/tests/glfwinfo: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o
deps/glfw/tests/glfwinfo: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o
deps/glfw/tests/glfwinfo: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o
deps/glfw/tests/glfwinfo: deps/glfw/tests/CMakeFiles/glfwinfo.dir/build.make
deps/glfw/tests/glfwinfo: deps/glfw/src/libglfw3.a
deps/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
deps/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/librt.so
deps/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
deps/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libX11.so
deps/glfw/tests/glfwinfo: deps/glfw/tests/CMakeFiles/glfwinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable glfwinfo"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfwinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/glfw/tests/CMakeFiles/glfwinfo.dir/build: deps/glfw/tests/glfwinfo

.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/build

deps/glfw/tests/CMakeFiles/glfwinfo.dir/requires: deps/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires
deps/glfw/tests/CMakeFiles/glfwinfo.dir/requires: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires
deps/glfw/tests/CMakeFiles/glfwinfo.dir/requires: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires
deps/glfw/tests/CMakeFiles/glfwinfo.dir/requires: deps/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires

.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/requires

deps/glfw/tests/CMakeFiles/glfwinfo.dir/clean:
	cd /home/max/code/repos/Cubes/deps/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/glfwinfo.dir/cmake_clean.cmake
.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/clean

deps/glfw/tests/CMakeFiles/glfwinfo.dir/depend:
	cd /home/max/code/repos/Cubes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/code/repos/Cubes /home/max/code/repos/Cubes/deps/glfw/tests /home/max/code/repos/Cubes /home/max/code/repos/Cubes/deps/glfw/tests /home/max/code/repos/Cubes/deps/glfw/tests/CMakeFiles/glfwinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deps/glfw/tests/CMakeFiles/glfwinfo.dir/depend
