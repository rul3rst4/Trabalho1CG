CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Iimgui -Iimgui/backends $(shell pkg-config --cflags glfw3 glew)
LDFLAGS = -L$(CMAKE_SOURCE_DIR)/resource -Wl,-rpath,'$$ORIGIN/resource' $(shell pkg-config --libs glfw3 glew) -lGL -Lresource -lzlibstatic -lassimp

SRCS = main.cpp \
       imgui/imgui.cpp \
       imgui/imgui_demo.cpp \
       imgui/imgui_draw.cpp \
       imgui/backends/imgui_impl_glfw.cpp \
       imgui/backends/imgui_impl_opengl3.cpp \
       imgui/imgui_tables.cpp \
       imgui/imgui_widgets.cpp \
       imgui/misc/cpp/imgui_stdlib.cpp \
       Renderer.cpp \
       ShaderProgram.cpp \
       Model.cpp \
       Mesh.cpp \
       Camera.cpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: mesh

mesh: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

copy_resources:
	cp -r resource $(CMAKE_CURRENT_BINARY_DIR)

clean:
	rm -f $(OBJS) mesh