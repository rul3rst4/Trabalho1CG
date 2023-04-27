//
// Created by ander on 4/25/2023.
//

#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures) {
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    setupMesh();
}

Mesh::Mesh() {
    GLCall(glGenVertexArrays(1, &VAO));
    GLCall(glGenBuffers(1, &VBO));
    GLCall(glGenBuffers(1, &EBO));
}

Mesh::~Mesh(){}

void Mesh::setupMesh() {
    GLCall(glGenVertexArrays(1, &VAO));
    GLCall(glGenBuffers(1, &VBO));
    GLCall(glGenBuffers(1, &EBO));

    GLCall(glBindVertexArray(VAO));

    GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_POSITION));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_NORMAL));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TEXCOORD, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TEXCOORD));

    glBindVertexArray(0);
}

void Mesh::updateMesh() {
    GLCall(glBindVertexArray(VAO));

    GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_POSITION));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_NORMAL));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TEXCOORD, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TEXCOORD));

    glBindVertexArray(0);
}

void Mesh::updateVectors() {
    GLCall(glBindVertexArray(VAO));

    auto u = vertices[0].Position - vertices[1].Position;
    auto v = vertices[2].Position - vertices[1].Position;
    auto O = vertices[1].Position;
    vertices.clear();

    Vertex verto{};
    verto.Position = O;
    vertices.push_back(verto);

    Vertex vertu{};
    vertu.Position = u;
    vertices.push_back(vertu);

    Vertex vertv{};
    vertv.Position = v;
    vertices.push_back(vertv);

    indices.clear();
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(0);
    indices.push_back(2);

    GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_POSITION));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_NORMAL));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TEXCOORD, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TEXCOORD));

    glBindVertexArray(0);
}

void Mesh::draw(ShaderProgram& shader) {
    GLCall(glBindVertexArray(VAO));
    shader.use();
    glDrawElements(draw_type, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    //camera.update();

    //ImVec2 delta = ImGui::GetMouseDragDelta(ImGuiMouseButton_::ImGuiMouseButton_Left);
    //// retrieve the matrix uniform locations
    //unsigned int modelLoc = glGetUniformLocation(shader.programID, "model");
    //unsigned int viewLoc = glGetUniformLocation(shader.programID, "view");
    //unsigned int projecLoc = glGetUniformLocation(shader.programID, "projection");

    //glm::vec3 cubePositions[] = {
    //	glm::vec3(0.0f,  0.0f,  0.0f),
    //	glm::vec3(2.0f,  5.0f, -15.0f),
    //	glm::vec3(-1.5f, -2.2f, -2.5f),
    //	glm::vec3(-3.8f, -2.0f, -12.3f),
    //	glm::vec3(2.4f, -0.4f, -3.5f),
    //	glm::vec3(-1.7f,  3.0f, -7.5f),
    //	glm::vec3(1.3f, -2.0f, -2.5f),
    //	glm::vec3(1.5f,  2.0f, -2.5f),
    //	glm::vec3(1.5f,  0.2f, -1.5f),
    //	glm::vec3(-1.3f,  1.0f, -1.5f)
    //};

    //glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)1280 / (float)720, 0.1f, 100.0f);
    //glm::mat4 view = camera.GetViewMatrix();
    //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    //glUniformMatrix4fv(projecLoc, 1, GL_FALSE, &projection[0][0]);

    //for (int i = 0; i < 10; i++) {
    //	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //	model = glm::translate(model, cubePositions[i]);
    //	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    //	glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3.0);
    //}
    //GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
