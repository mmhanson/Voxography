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
include deps/glfw/tests/CMakeFiles/threads.dir/depend.make

# Include the progress variables for this target.
include deps/glfw/tests/CMakeFiles/threads.dir/progress.make

# Include the compile flags for this target's objects.
include deps/glfw/tests/CMakeFiles/threads.dir/flags.make

deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o: deps/glfw/tests/CMakeFiles/threads.dir/flags.make
deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o: deps/glfw/tests/threads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/threads.dir/threads.c.o   -c /home/max/code/repos/Cubes/deps/glfw/tests/threads.c

deps/glfw/tests/CMakeFiles/threads.dir/threads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/threads.c.i"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/code/repos/Cubes/deps/glfw/tests/threads.c > CMakeFiles/threads.dir/threads.c.i

deps/glfw/tests/CMakeFiles/threads.dir/threads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/threads.c.s"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/code/repos/Cubes/deps/glfw/tests/threads.c -o CMakeFiles/threads.dir/threads.c.s

deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires:

.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires

deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides: deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires
	$(MAKE) -f deps/glfw/tests/CMakeFiles/threads.dir/build.make deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides.build
.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides

deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.provides.build: deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o


deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o: deps/glfw/tests/CMakeFiles/threads.dir/flags.make
deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o: deps/glfw/deps/tinycthread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/threads.dir/__/deps/tinycthread.c.o   -c /home/max/code/repos/Cubes/deps/glfw/deps/tinycthread.c

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/__/deps/tinycthread.c.i"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/code/repos/Cubes/deps/glfw/deps/tinycthread.c > CMakeFiles/threads.dir/__/deps/tinycthread.c.i

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/__/deps/tinycthread.c.s"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/code/repos/Cubes/deps/glfw/deps/tinycthread.c -o CMakeFiles/threads.dir/__/deps/tinycthread.c.s

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires:

.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires
	$(MAKE) -f deps/glfw/tests/CMakeFiles/threads.dir/build.make deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides.build
.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.provides.build: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o


deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o: deps/glfw/tests/CMakeFiles/threads.dir/flags.make
deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o: deps/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/threads.dir/__/deps/glad_gl.c.o   -c /home/max/code/repos/Cubes/deps/glfw/deps/glad_gl.c

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threads.dir/__/deps/glad_gl.c.i"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/code/repos/Cubes/deps/glfw/deps/glad_gl.c > CMakeFiles/threads.dir/__/deps/glad_gl.c.i

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threads.dir/__/deps/glad_gl.c.s"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/code/repos/Cubes/deps/glfw/deps/glad_gl.c -o CMakeFiles/threads.dir/__/deps/glad_gl.c.s

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.requires:

.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.requires

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.provides: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.requires
	$(MAKE) -f deps/glfw/tests/CMakeFiles/threads.dir/build.make deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.provides.build
.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.provides

deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.provides.build: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o


# Object files for target threads
threads_OBJECTS = \
"CMakeFiles/threads.dir/threads.c.o" \
"CMakeFiles/threads.dir/__/deps/tinycthread.c.o" \
"CMakeFiles/threads.dir/__/deps/glad_gl.c.o"

# External object files for target threads
threads_EXTERNAL_OBJECTS =

deps/glfw/tests/threads: deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o
deps/glfw/tests/threads: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o
deps/glfw/tests/threads: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o
deps/glfw/tests/threads: deps/glfw/tests/CMakeFiles/threads.dir/build.make
deps/glfw/tests/threads: deps/glfw/src/libglfw3.a
deps/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libm.so
deps/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/librt.so
deps/glfw/tests/threads: /usr/lib/x86_64-linux-gnu/libX11.so
deps/glfw/tests/threads: deps/glfw/tests/CMakeFiles/threads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/max/code/repos/Cubes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable threads"
	cd /home/max/code/repos/Cubes/deps/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threads.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/glfw/tests/CMakeFiles/threads.dir/build: deps/glfw/tests/threads

.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/build

deps/glfw/tests/CMakeFiles/threads.dir/requires: deps/glfw/tests/CMakeFiles/threads.dir/threads.c.o.requires
deps/glfw/tests/CMakeFiles/threads.dir/requires: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/tinycthread.c.o.requires
deps/glfw/tests/CMakeFiles/threads.dir/requires: deps/glfw/tests/CMakeFiles/threads.dir/__/deps/glad_gl.c.o.requires

.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/requires

deps/glfw/tests/CMakeFiles/threads.dir/clean:
	cd /home/max/code/repos/Cubes/deps/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/threads.dir/cmake_clean.cmake
.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/clean

deps/glfw/tests/CMakeFiles/threads.dir/depend:
	cd /home/max/code/repos/Cubes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/code/repos/Cubes /home/max/code/repos/Cubes/deps/glfw/tests /home/max/code/repos/Cubes /home/max/code/repos/Cubes/deps/glfw/tests /home/max/code/repos/Cubes/deps/glfw/tests/CMakeFiles/threads.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deps/glfw/tests/CMakeFiles/threads.dir/depend

