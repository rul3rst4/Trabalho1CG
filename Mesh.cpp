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

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TEXCOORD));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TANGENT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TANGENT));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_BITANGENT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_BITANGENT));

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

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TEXCOORD));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TANGENT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TANGENT));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_BITANGENT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_BITANGENT));

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

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TEXCOORD));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_TANGENT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_TANGENT));

    glVertexAttribPointer(AttributeIndex::ATTRIBUTE_BITANGENT, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
    GLCall(glEnableVertexAttribArray(AttributeIndex::ATTRIBUTE_BITANGENT));

    glBindVertexArray(0);
}

void Mesh::draw(ShaderProgram& shader) {
    GLCall(glBindVertexArray(VAO));
    glDrawElements(draw_type, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
