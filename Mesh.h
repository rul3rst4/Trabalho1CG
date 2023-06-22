//
// Created by ander on 4/25/2023.
//

#ifndef TRABALHO1_MESH_H
#define TRABALHO1_MESH_H

#include <GL/glew.h>
#include "ShaderProgram.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include <GL/glew.h>
#include "GLHelpers.h"
#include <vector>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    std::string type;
};

class Mesh {
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
public:
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;
    GLuint draw_type = GL_TRIANGLES;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    Mesh();
    ~Mesh();
    void draw(ShaderProgram& shader);
    void setupMesh();
    void updateMesh();
    void updateVectors();
};


#endif //TRABALHO1_MESH_H
