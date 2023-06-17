//
// Created by ander on 4/25/2023.
//

#include "Renderer.h"
#include <imgui_internal.h>
#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int loadCubemap(std::vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                         0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
            );
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap tex failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}

Renderer::Renderer(std::string model_path) {
    std::string pathNameCube = R"(./resource/cube.object)";
    models.emplace_back(pathNameCube.c_str());
    add_model_path(pathNameCube);
    add_bounding_box(models.back());

    cubemapId = loadCubemap({
                "./resource/skybox/right.jpg",
                "./resource/skybox/left.jpg",
                "./resource/skybox/top.jpg",
                "./resource/skybox/bottom.jpg",
                "./resource/skybox/front.jpg",
                "./resource/skybox/back.jpg"
    });

    if (!model_path.empty()) {
        models.emplace_back(model_path.c_str());
        add_bounding_box(models.back());
        add_model_path(model_path);
        add_coordinate_system();
        return;
    }

    std::string pathName = R"(./resource/backpack.obj)";
    models.emplace_back(pathName.c_str());
    add_bounding_box(models.back());
    add_model_path(pathName);

    add_coordinate_system();
}

void Renderer::add_coordinate_system() {
    Model model;
    Mesh mesh;
    static int indices = 0;
    mesh.draw_type = GL_LINES;

    std::vector<glm::vec3> vtx
            {
                    {-25000, 0,      0},
                    {25000,  0,      0},
                    {0,      25000,  0},
                    {0,      -25000, 0},
                    {0,      0,      25000},
                    {0,      0,      -25000}
            };

    for (const auto &v: vtx) {
        Vertex vertex{};
        vertex.Position = v;
        mesh.vertices.push_back(vertex);
        mesh.indices.push_back(indices);
        indices++;
    }
    mesh.updateMesh();
    model.meshes.push_back(mesh);
    models.emplace_back(model);
}

void flip_bit(ObjectSelectMode &mode, ObjectSelectMode bit) {
    mode = static_cast<ObjectSelectMode>(static_cast<int>(mode) ^ static_cast<int>(bit));
}

void activate_transform_mode(ObjectSelectMode &mode, ObjectSelectMode bit) {
    mode = static_cast<ObjectSelectMode>(mode & (ObjectSelectMode::Lighting | ObjectSelectMode::Texture | ObjectSelectMode::NormalMap));
    flip_bit(mode, bit);
}

void Renderer::draw() {
    shaderProgram.use();

    static bool freeMode = true;

    if (ImGui::IsKeyPressed(ImGuiKey_T)){
        freeMode = false;
        activate_transform_mode(objectSelectMode, ObjectSelectMode::Translate);
    } else if (ImGui::IsKeyPressed(ImGuiKey_R)){
        freeMode = false;
        activate_transform_mode(objectSelectMode, ObjectSelectMode::Rotate);
    } else if (ImGui::IsKeyPressed(ImGuiKey_S)){
        freeMode = false;
        activate_transform_mode(objectSelectMode, ObjectSelectMode::Scale);
    } else if (ImGui::IsKeyPressed(ImGuiKey_1)){
        freeMode = false;
        flip_bit(objectSelectMode, ObjectSelectMode::Lighting);
    } else if (ImGui::IsKeyPressed(ImGuiKey_2)){
        freeMode = false;
        flip_bit(objectSelectMode, ObjectSelectMode::Texture);
    } else if (ImGui::IsKeyPressed(ImGuiKey_3)){
        freeMode = false;
        flip_bit(objectSelectMode, ObjectSelectMode::NormalMap);
    } else if (ImGui::IsKeyPressed(ImGuiKey_E)){
        freeMode = true;
        objectSelectMode = static_cast<ObjectSelectMode>(objectSelectMode & (ObjectSelectMode::Lighting |ObjectSelectMode::Texture |ObjectSelectMode::NormalMap));
    }

    float mouseX_NDC = (2.0f * mouse_pos.x) / display_w - 1.0f;
    float mouseY_NDC = 1.0f - (2.0f * mouse_pos.y) / display_h;
    ImGui::Begin("Mouse imgui");
    ImGui::Text("Mouse X: %f - Y: %f", mouse_pos.x, mouse_pos.y);
    ImGui::Text("Mouse(NDC) X: %f - Y: %f", mouseX_NDC, mouseY_NDC);
    ImGui::Checkbox("FreeMode", &freeMode);

    ImGui::DragFloat3("Scale", &scale[0], 0.1);
    ImGui::DragFloat3("Translate", &translate[0], 0.1);
//    ImGui::DragFloat("Rotate (Angle)", &angle, 0.25);
    ImGui::DragFloat3("Rotate (Axis)", &rotate_axis[0], 0.1);
    ImGui::DragFloat3("Camera Pos", &camera.Position[0], 0.1);
    ImGui::End();

    if (ImGui::IsKeyPressed(ImGuiKey_UpArrow)) {
        apply_transform_based_on_mode(Axis::Y, 0.1f);
    }
    if (ImGui::IsKeyPressed(ImGuiKey_DownArrow)) {
        apply_transform_based_on_mode(Axis::Y, -0.1f);
    }
    if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow)) {
        apply_transform_based_on_mode(Axis::X, -0.1f);
    }
    if (ImGui::IsKeyPressed(ImGuiKey_RightArrow)) {
        apply_transform_based_on_mode(Axis::X, 0.1f);
    }
    if (ImGui::IsKeyPressed(ImGuiKey_A)) {
        apply_transform_based_on_mode(Axis::Z, 0.1f);
    }
    if (ImGui::IsKeyPressed(ImGuiKey_D)) {
        apply_transform_based_on_mode(Axis::Z, -0.1f);
    }

    glm::vec3 lightPos(0.0f, 1.0f, 2.0f);
    glm::mat4 rotate_cam(1.0f);
    glm::mat4 view = camera.GetViewMatrix();

    if (sceneMode == SceneMode::Fly && freeMode) {
        camera.update();
    }

    unsigned int modelLoc = glGetUniformLocation(shaderProgram.programID, "model");
    unsigned int viewLoc = glGetUniformLocation(shaderProgram.programID, "view");
    unsigned int projecLoc = glGetUniformLocation(shaderProgram.programID, "projection");

    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float) display_w / (float) display_h, 0.1f, 25000.0f);

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(projecLoc, 1, GL_FALSE, &projection[0][0]);

    glm::mat4 modelTransform = glm::mat4(1.0f);

    modelTransform = glm::translate(modelTransform, translate);
    modelTransform = glm::rotate(modelTransform, angles.x, glm::vec3(1.0f, 0.0f, 0.0f));
    modelTransform = glm::rotate(modelTransform, angles.y, glm::vec3(0.0f, 1.0f, 0.0f));
    modelTransform = glm::rotate(modelTransform, angles.z, glm::vec3(0.0f, 0.0f, 1.0f));
    modelTransform = glm::scale(modelTransform, scale);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &modelTransform[0][0]);

    list_models();

    auto index = 0;
    for (auto &model: models) {
        if (index == 0) {
            lightShaderProgram.use();
            unsigned int modelLoc = glGetUniformLocation(lightShaderProgram.programID, "model");
            unsigned int viewLoc = glGetUniformLocation(lightShaderProgram.programID, "view");
            unsigned int projecLoc = glGetUniformLocation(lightShaderProgram.programID, "projection");

            glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float) display_w / (float) display_h,
                                                    0.1f, 100.0f);

            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
            glUniformMatrix4fv(projecLoc, 1, GL_FALSE, &projection[0][0]);

            glm::mat4 modelTransform = glm::mat4(1.0f);

            modelTransform = glm::translate(modelTransform, lightPos);
            modelTransform = glm::scale(modelTransform, glm::vec3(0.3f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &modelTransform[0][0]);
            model.draw(lightShaderProgram);
        } else if(index == models.size() - 1) {
            shaderProgram.use();

            unsigned int objectColorFrag = glGetUniformLocation(shaderProgram.programID, "objectColor");
            unsigned int lightColorFrag = glGetUniformLocation(shaderProgram.programID, "lightColor");
            unsigned int lightPosFrag = glGetUniformLocation(shaderProgram.programID, "lightPos");
            unsigned int viewPosFrag = glGetUniformLocation(shaderProgram.programID, "viewPos");
            unsigned int isLighting = glGetUniformLocation(shaderProgram.programID, "isLighting");
            unsigned int isTexture = glGetUniformLocation(shaderProgram.programID, "isTexture");

            glm::mat4 modelTransform = glm::mat4(1.0f);
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &modelTransform[0][0]);

            glUniform3f(objectColorFrag, 1.0f, 0.5f, 0.31f);
            glUniform3f(lightColorFrag, 1.0f, 1.0f, 1.0f);
            glUniform3f(lightPosFrag, lightPos.x, lightPos.y, lightPos.z);
            glUniform3f(viewPosFrag, camera.Position.x, camera.Position.y, camera.Position.z);
            glUniform1i(isLighting, ((int)objectSelectMode & (int)ObjectSelectMode::Lighting) != 0);
            bool isTextureOn = ((int)objectSelectMode & (int)ObjectSelectMode::Texture) != 0;
            glUniform1i(isTexture, isTextureOn);

            if (isTextureOn) {
                glUniform1i(glGetUniformLocation(shaderProgram.programID, "cubemap"), 0);
                glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapId);
                glActiveTexture(GL_TEXTURE0);
            }

            model.draw(shaderProgram);
        } else {
            shaderProgram.use();

            unsigned int objectColorFrag = glGetUniformLocation(shaderProgram.programID, "objectColor");
            unsigned int lightColorFrag = glGetUniformLocation(shaderProgram.programID, "lightColor");
            unsigned int lightPosFrag = glGetUniformLocation(shaderProgram.programID, "lightPos");
            unsigned int viewPosFrag = glGetUniformLocation(shaderProgram.programID, "viewPos");

            glUniform3f(objectColorFrag, 1.0f, 0.5f, 0.31f);
            glUniform3f(lightColorFrag, 1.0f, 1.0f, 1.0f);
            glUniform3f(lightPosFrag, lightPos.x, lightPos.y, lightPos.z);
            glUniform3f(viewPosFrag, camera.Position.x, camera.Position.y, camera.Position.z);

            model.draw(shaderProgram);
        }
        index++;
    }

    if (bounding_box) {
        index = 0;
        for (auto &model: models_bounding_box) {
            if (index == 0) {
                lightShaderProgram.use();
                unsigned int modelLoc = glGetUniformLocation(lightShaderProgram.programID, "model");
                unsigned int viewLoc = glGetUniformLocation(lightShaderProgram.programID, "view");
                unsigned int projecLoc = glGetUniformLocation(lightShaderProgram.programID, "projection");

                glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float) display_w / (float) display_h,
                                                        0.1f, 100.0f);

                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
                glUniformMatrix4fv(projecLoc, 1, GL_FALSE, &projection[0][0]);

                glm::mat4 modelTransform = glm::mat4(1.0f);

                modelTransform = glm::translate(modelTransform, lightPos);
                modelTransform = glm::scale(modelTransform, glm::vec3(0.3f));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &modelTransform[0][0]);
                model.draw(lightShaderProgram);
            } else {
                shaderProgram.use();

                unsigned int objectColorFrag = glGetUniformLocation(shaderProgram.programID, "objectColor");
                unsigned int lightColorFrag = glGetUniformLocation(shaderProgram.programID, "lightColor");
                unsigned int lightPosFrag = glGetUniformLocation(shaderProgram.programID, "lightPos");
                unsigned int viewPosFrag = glGetUniformLocation(shaderProgram.programID, "viewPos");

                glUniform3f(objectColorFrag, 1.0f, 0.5f, 0.31f);
                glUniform3f(lightColorFrag, 1.0f, 1.0f, 1.0f);
                glUniform3f(lightPosFrag, lightPos.x, lightPos.y, lightPos.z);
                glUniform3f(viewPosFrag, camera.Position.x, camera.Position.y, camera.Position.z);

                model.draw(shaderProgram);
            }
            index++;
        }
    }
}

void Renderer::add_model_path(const std::string_view &path) {
    auto idx = path.find_last_of("\\");
    paths.emplace_back(path.substr(idx + 1));
}

void Renderer::list_models() {
    ImGui::Begin("Renderer");

    ImGui::Checkbox("Render Bounding Box", &bounding_box);

    static int currentItem;
    static const char *items[] = {"Fly", "Selection"};
    const char *combo_preview_value = items[currentItem];
    if (ImGui::BeginCombo("combo 1", combo_preview_value)) {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++) {
            const bool is_selected = (currentItem == n);
            if (ImGui::Selectable(items[n], is_selected)) {
                currentItem = n;
                sceneMode = (SceneMode) currentItem;
            }

            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    static char modelPath[] = "";
    ImGui::InputText("Model path", modelPath, 256);
    if (ImGui::Button("Add model")) {
        models.emplace_back(modelPath);
        add_bounding_box(models.back());
        add_model_path(modelPath);
    }

    for (int i = 0; i < models.size(); i++) {
        auto str = paths.size() > i ? paths[i] : "";
        ImGui::Text("Model %s", str.c_str());
        ImGui::SameLine();
        char deleteLabel[50]{0};
        sprintf(deleteLabel, "Delete %d", i);
        if (ImGui::Button(deleteLabel)) {
            models.erase(models.begin() + i);
            models_bounding_box.erase(models_bounding_box.begin() + i);
            paths.erase(paths.begin() + i);
        }
    }

    ImGui::End();
}

void Renderer::add_bounding_box(Model &model) {
    auto replace_while_not_found = [](std::string &str, const std::string &from, const std::string &to) {
        auto idx = str.find(from);
        while (idx != std::string::npos) {
            str.replace(idx, from.size(), to);
            idx = str.find(from);
        }
    };

    std::string newCube = CubeObject;
    replace_while_not_found(newCube, "{0}", std::to_string(model.minX));
    replace_while_not_found(newCube, "{1}", std::to_string(model.minY));
    replace_while_not_found(newCube, "{2}", std::to_string(model.minZ));
    replace_while_not_found(newCube, "{3}", std::to_string(model.maxX));
    replace_while_not_found(newCube, "{4}", std::to_string(model.maxY));
    replace_while_not_found(newCube, "{5}", std::to_string(model.maxZ));

    std::string_view view = newCube;
    models_bounding_box.emplace_back(view);
}

void Renderer::apply_transform_based_on_mode(Axis axis, float value) {
    if (objectSelectMode == ObjectSelectMode::None) {
        return;
    } else if (objectSelectMode & ObjectSelectMode::Translate) {
        if (axis == Axis::X) {
            translate.x += value;
        } else if (axis == Axis::Y) {
            translate.y += value;
        } else if (axis == Axis::Z) {
            translate.z += value;
        }
    } else if (objectSelectMode & ObjectSelectMode::Rotate) {
        if (axis == Axis::X) {
            rotate_axis = glm::vec3(0.0f, 1.0f, 0.0f);
            angles.y += value;
        } else if (axis == Axis::Y) {
            rotate_axis = glm::vec3(1.0f, 0.0f, 0.0f);
            angles.x += value;
        } else if (axis == Axis::Z) {
            rotate_axis = glm::vec3(0.0f, 0.0f, 1.0f);
            angles.z += value;
        }
    } else if (objectSelectMode & ObjectSelectMode::Scale) {
        if (axis == Axis::X) {
            scale.x += value;
        } else if (axis == Axis::Y) {
            scale.y += value;
        } else if (axis == Axis::Z) {
            scale.z += value;
        }
    }
}
