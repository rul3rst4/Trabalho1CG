# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build"

# Include any dependencies generated for this target.
include CMakeFiles/Trabalho1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Trabalho1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Trabalho1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Trabalho1.dir/flags.make

CMakeFiles/Trabalho1.dir/main.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/main.cpp.o: ../main.cpp
CMakeFiles/Trabalho1.dir/main.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Trabalho1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/main.cpp.o -MF CMakeFiles/Trabalho1.dir/main.cpp.o.d -o CMakeFiles/Trabalho1.dir/main.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/main.cpp"

CMakeFiles/Trabalho1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/main.cpp" > CMakeFiles/Trabalho1.dir/main.cpp.i

CMakeFiles/Trabalho1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/main.cpp" -o CMakeFiles/Trabalho1.dir/main.cpp.s

CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o: ../imgui/imgui.cpp
CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui.cpp"

CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui.cpp" > CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.i

CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui.cpp" -o CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.s

CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o: ../imgui/imgui_demo.cpp
CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_demo.cpp"

CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_demo.cpp" > CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.i

CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_demo.cpp" -o CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.s

CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o: ../imgui/imgui_draw.cpp
CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_draw.cpp"

CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_draw.cpp" > CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.i

CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_draw.cpp" -o CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.s

CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o: ../imgui/backends/imgui_impl_glfw.cpp
CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/backends/imgui_impl_glfw.cpp"

CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/backends/imgui_impl_glfw.cpp" > CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.i

CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/backends/imgui_impl_glfw.cpp" -o CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.s

CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o: ../imgui/backends/imgui_impl_opengl3.cpp
CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/backends/imgui_impl_opengl3.cpp"

CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/backends/imgui_impl_opengl3.cpp" > CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.i

CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/backends/imgui_impl_opengl3.cpp" -o CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.s

CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o: ../imgui/imgui_tables.cpp
CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_tables.cpp"

CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_tables.cpp" > CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.i

CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_tables.cpp" -o CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.s

CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o: ../imgui/imgui_widgets.cpp
CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_widgets.cpp"

CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_widgets.cpp" > CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.i

CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/imgui_widgets.cpp" -o CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.s

CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o: ../imgui/misc/cpp/imgui_stdlib.cpp
CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o -MF CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o.d -o CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/misc/cpp/imgui_stdlib.cpp"

CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/misc/cpp/imgui_stdlib.cpp" > CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.i

CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/imgui/misc/cpp/imgui_stdlib.cpp" -o CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.s

CMakeFiles/Trabalho1.dir/Renderer.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/Renderer.cpp.o: ../Renderer.cpp
CMakeFiles/Trabalho1.dir/Renderer.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Trabalho1.dir/Renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/Renderer.cpp.o -MF CMakeFiles/Trabalho1.dir/Renderer.cpp.o.d -o CMakeFiles/Trabalho1.dir/Renderer.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Renderer.cpp"

CMakeFiles/Trabalho1.dir/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Renderer.cpp" > CMakeFiles/Trabalho1.dir/Renderer.cpp.i

CMakeFiles/Trabalho1.dir/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Renderer.cpp" -o CMakeFiles/Trabalho1.dir/Renderer.cpp.s

CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o: ../ShaderProgram.cpp
CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o -MF CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o.d -o CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/ShaderProgram.cpp"

CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/ShaderProgram.cpp" > CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.i

CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/ShaderProgram.cpp" -o CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.s

CMakeFiles/Trabalho1.dir/Model.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/Model.cpp.o: ../Model.cpp
CMakeFiles/Trabalho1.dir/Model.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Trabalho1.dir/Model.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/Model.cpp.o -MF CMakeFiles/Trabalho1.dir/Model.cpp.o.d -o CMakeFiles/Trabalho1.dir/Model.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Model.cpp"

CMakeFiles/Trabalho1.dir/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Model.cpp" > CMakeFiles/Trabalho1.dir/Model.cpp.i

CMakeFiles/Trabalho1.dir/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Model.cpp" -o CMakeFiles/Trabalho1.dir/Model.cpp.s

CMakeFiles/Trabalho1.dir/Mesh.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/Mesh.cpp.o: ../Mesh.cpp
CMakeFiles/Trabalho1.dir/Mesh.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Trabalho1.dir/Mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/Mesh.cpp.o -MF CMakeFiles/Trabalho1.dir/Mesh.cpp.o.d -o CMakeFiles/Trabalho1.dir/Mesh.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Mesh.cpp"

CMakeFiles/Trabalho1.dir/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Mesh.cpp" > CMakeFiles/Trabalho1.dir/Mesh.cpp.i

CMakeFiles/Trabalho1.dir/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Mesh.cpp" -o CMakeFiles/Trabalho1.dir/Mesh.cpp.s

CMakeFiles/Trabalho1.dir/Camera.cpp.o: CMakeFiles/Trabalho1.dir/flags.make
CMakeFiles/Trabalho1.dir/Camera.cpp.o: ../Camera.cpp
CMakeFiles/Trabalho1.dir/Camera.cpp.o: CMakeFiles/Trabalho1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Trabalho1.dir/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trabalho1.dir/Camera.cpp.o -MF CMakeFiles/Trabalho1.dir/Camera.cpp.o.d -o CMakeFiles/Trabalho1.dir/Camera.cpp.o -c "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Camera.cpp"

CMakeFiles/Trabalho1.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trabalho1.dir/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Camera.cpp" > CMakeFiles/Trabalho1.dir/Camera.cpp.i

CMakeFiles/Trabalho1.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trabalho1.dir/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/Camera.cpp" -o CMakeFiles/Trabalho1.dir/Camera.cpp.s

# Object files for target Trabalho1
Trabalho1_OBJECTS = \
"CMakeFiles/Trabalho1.dir/main.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o" \
"CMakeFiles/Trabalho1.dir/Renderer.cpp.o" \
"CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o" \
"CMakeFiles/Trabalho1.dir/Model.cpp.o" \
"CMakeFiles/Trabalho1.dir/Mesh.cpp.o" \
"CMakeFiles/Trabalho1.dir/Camera.cpp.o"

# External object files for target Trabalho1
Trabalho1_EXTERNAL_OBJECTS =

Trabalho1: CMakeFiles/Trabalho1.dir/main.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/imgui.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/imgui_demo.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/imgui_draw.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_glfw.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/backends/imgui_impl_opengl3.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/imgui_tables.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/imgui_widgets.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/imgui/misc/cpp/imgui_stdlib.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/Renderer.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/ShaderProgram.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/Model.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/Mesh.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/Camera.cpp.o
Trabalho1: CMakeFiles/Trabalho1.dir/build.make
Trabalho1: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
Trabalho1: /usr/lib/x86_64-linux-gnu/libGLEW.so
Trabalho1: /usr/lib/x86_64-linux-gnu/libOpenGL.so
Trabalho1: /usr/lib/x86_64-linux-gnu/libGLX.so
Trabalho1: /usr/lib/x86_64-linux-gnu/libGLU.so
Trabalho1: ../resource/libzlibstatic.a
Trabalho1: ../resource/libassimp.so
Trabalho1: CMakeFiles/Trabalho1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable Trabalho1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Trabalho1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Trabalho1.dir/build: Trabalho1
.PHONY : CMakeFiles/Trabalho1.dir/build

CMakeFiles/Trabalho1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Trabalho1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Trabalho1.dir/clean

CMakeFiles/Trabalho1.dir/depend:
	cd "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1" "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1" "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build" "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build" "/mnt/c/dev/UTFPR/Computer Graphics/Trabalho1/build/CMakeFiles/Trabalho1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Trabalho1.dir/depend
