cmake_minimum_required(VERSION 3.22)
project(Trabalho1)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_SKIP_BUILD_RPATH FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH "\${ORIGIN}/resource")

#find_package(assimp CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

include_directories("imgui")
include_directories("imgui/backends")
include_directories("include")

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})
#include_directories(${ASSIMP_INCLUDE_DIRS})

file(GLOB resources "./resource")

file(COPY ${resources} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
link_directories(${CMAKE_SOURCE_DIR}/resource)
add_executable(Trabalho1 main.cpp ./imgui/imgui.cpp ./imgui/imgui_demo.cpp ./imgui/imgui_draw.cpp
        ./imgui/backends/imgui_impl_glfw.cpp ./imgui/backends/imgui_impl_opengl3.cpp
        ./imgui/imgui_internal.h ./imgui/imgui_tables.cpp ./imgui/imgui_widgets.cpp
        ./imgui/imstb_rectpack.h ./imgui/imstb_textedit.h ./imgui/imstb_truetype.h
        ./imgui/misc/cpp/imgui_stdlib.cpp ./imgui/misc/cpp/imgui_stdlib.h Renderer.cpp
        Renderer.h ShaderProgram.cpp ShaderProgram.h GLHelpers.h Model.cpp Model.h Mesh.cpp Mesh.h Camera.cpp Camera.h)

#target_link_libraries(Trabalho1 PRIVATE glfw GLEW::GLEW ${OPENGL_LIBRARIES} assimp::assimp)
target_link_libraries(Trabalho1 PRIVATE glfw GLEW::GLEW ${OPENGL_LIBRARIES} ${CMAKE_SOURCE_DIR}/resource/libzlibstatic.a ${CMAKE_SOURCE_DIR}/resource/libassimp.so)
