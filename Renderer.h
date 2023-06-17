//
// Created by ander on 4/25/2023.
//

#ifndef TRABALHO1_RENDERER_H
#define TRABALHO1_RENDERER_H

#include "ShaderProgram.h"
#include "GLHelpers.h"
#include "Model.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include "Camera.h"

enum SceneMode : int {
    Fly = 0,
    ObjectSelect,
    COUNT
};

enum ObjectSelectMode : int {
    None = 0x00,
    Translate = 0x01,
    Rotate = 0x02,
    Scale = 0x04,
    Lighting = 0x08,
    Texture = 0x10,
    NormalMap = 0x20
};

enum class Axis : int {
    X = 0,
    Y,
    Z
};

class Renderer {
public:
    glm::dvec2 mouse_pos;
    int display_w;
    int display_h;
    ShaderProgram shaderProgram{ "./resource/default.frag", "./resource/default.vert" };
    ShaderProgram lightShaderProgram{ "./resource/lighting.frag", "./resource/lighting.vert" };
    std::vector<Model> models;
    std::vector<Model> models_bounding_box;
    bool bounding_box = false;
    std::vector<std::string> paths;
    SceneMode sceneMode{SceneMode::Fly};
    Camera camera{ glm::vec3(-4.0f, 4.0f, 7.7f) };
    ObjectSelectMode objectSelectMode{ObjectSelectMode::None};
    glm::vec3 scale{1.0f, 1.0f, 1.0f};
    glm::vec3 translate{0.0f, 0.0f, 0.0f};
    glm::vec3 rotate_axis{0.0f, 1.0f, 0.0f};
    glm::vec3 angles{0.0f, 0.0f, 0.0f};
    unsigned int cubemapId = -1;


    Renderer(std::string model_path = "");
    void draw();
    void add_model_path(const std::string_view& path);
    void list_models();
    void add_bounding_box(Model& model);
    void add_coordinate_system();
    void apply_transform_based_on_mode(Axis axis, float value);
};


#endif //TRABALHO1_RENDERER_H
