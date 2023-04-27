//
// Created by ander on 4/25/2023.
//

#ifndef TRABALHO1_MODEL_H
#define TRABALHO1_MODEL_H
#include <vector>
#include <string>
#include "ShaderProgram.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"

class Model {
public:
    float maxX{ (float)INT_MIN };
    float minX{ (float)INT_MAX };

    float maxY{ (float)INT_MIN };
    float minY{ (float)INT_MAX };

    float maxZ{ (float)INT_MIN };
    float minZ{ (float)INT_MAX };

    explicit Model() = default;
    explicit Model(const char* path);
    explicit Model(std::string_view& contents);
    void draw(ShaderProgram& shader);
    std::vector<Mesh> meshes;
private:
    // model data
    std::string directory;

    void loadModel(std::string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};


#endif //TRABALHO1_MODEL_H
