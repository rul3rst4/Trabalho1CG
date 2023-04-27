//
// Created by ander on 4/25/2023.
//

#ifndef TRABALHO1_SHADERPROGRAM_H
#define TRABALHO1_SHADERPROGRAM_H

#include <GL/glew.h>
#include "GlHelpers.h"
#include <fstream>
#include <sstream>

class ShaderProgram {
public:
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    GLuint programID;

    ShaderProgram(const char* fragShaderPath, const char* vertexShaderPath);
    void use() const;
    static std::string load_shader_file(const char* path);
};


#endif //TRABALHO1_SHADERPROGRAM_H
