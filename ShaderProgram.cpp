//
// Created by ander on 4/25/2023.
//

#include "ShaderProgram.h"

void ShaderProgram::use() const {
    GLCall(glUseProgram(programID));
}

ShaderProgram::ShaderProgram(const char *fragShaderPath, const char *vertexShaderPath) {
    vertexShaderID = GLResultCall(glCreateShader(GL_VERTEX_SHADER));
    fragmentShaderID = GLResultCall(glCreateShader(GL_FRAGMENT_SHADER));

    auto FragmentShaderSource = load_shader_file(fragShaderPath);
    auto VertexShaderSource = load_shader_file(vertexShaderPath);

    auto vtx_cstr = VertexShaderSource.c_str();
    auto frag_cstr = FragmentShaderSource.c_str();

    GLint Compiled;
    GLCall(glShaderSource(vertexShaderID, 1, &vtx_cstr, nullptr));
    GLCall(glCompileShader(vertexShaderID));
    GLCall(glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &Compiled));
    if (!Compiled)
    {
        std::cerr << "Failed to compile vertex shader!" << std::endl;
        PrintShaderInfoLog(vertexShaderID);
    }

    GLCall(glShaderSource(fragmentShaderID, 1, &frag_cstr, nullptr));
    GLCall(glCompileShader(fragmentShaderID));
    GLCall(glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &Compiled));
    if (!Compiled)
    {
        std::cerr << "Failed to compile fragment shader!" << std::endl;
        PrintShaderInfoLog(fragmentShaderID);
    }

    programID = GLResultCall(glCreateProgram());
    GLCall(glAttachShader(programID, vertexShaderID));
    GLCall(glAttachShader(programID, fragmentShaderID));
    GLCall(glBindAttribLocation(programID, AttributeIndex::ATTRIBUTE_POSITION, "position"));
    GLCall(glBindAttribLocation(programID, AttributeIndex::ATTRIBUTE_NORMAL, "normal"));
    GLCall(glLinkProgram(programID));
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

std::string ShaderProgram::load_shader_file(const char *path) {
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        shaderFile.open(path);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        return shaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        shaderFile.close();
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ - PATH: "<< path << std::endl;
    }

    return {};
}
