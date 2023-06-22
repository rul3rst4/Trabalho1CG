//
// Created by ander on 4/25/2023.
//

#ifndef TRABALHO1_GLHELPERS_H
#define TRABALHO1_GLHELPERS_H

#include <GL/glew.h>
#include <iostream>

enum AttributeIndex : GLuint
{
    ATTRIBUTE_POSITION = 0,
    ATTRIBUTE_COLOR = 1,
    ATTRIBUTE_NORMAL = 2,
    ATTRIBUTE_TANGENT = 3,
    ATTRIBUTE_BITANGENT = 4,
    ATTRIBUTE_TEXCOORD = 5,
};

static inline const std::string CubeObject = R"OBJ(
# Cube in .obj format
# Vertices
v {0} {1} {2}
v {3} {1} {2}
v {3} {4} {2}
v {0} {4} {2}
v {0} {1} {5}
v {3} {1} {5}
v {3} {4} {5}
v {0} {4} {5}

# Normals
vn 0.0 0.0 -1.0
vn 0.0 0.0 1.0
vn 0.0 -1.0 0.0
vn 0.0 1.0 0.0
vn -1.0 0.0 0.0
vn 1.0 0.0 0.0

# Faces
f 1//1 2//1 3//1
f 3//1 4//1 1//1
f 5//2 6//2 7//2
f 7//2 8//2 5//2
f 1//3 5//3 6//3
f 6//3 2//3 1//3
f 3//4 7//4 8//4
f 8//4 4//4 3//4
f 1//5 4//5 8//5
f 8//5 5//5 1//5
f 2//6 6//6 7//6
f 7//6 3//6 2//6
)OBJ";

inline void PrintOpenGLErrors(char const* const Function, char const* const File, int const Line)
{
    bool Succeeded = true;

    GLenum Error = glGetError();
    if (Error != GL_NO_ERROR)
    {
        char const* ErrorString = (char const*)gluErrorString(Error);
        if (ErrorString)
            std::cerr << ("OpenGL Error in %s at line %d calling function %s: '%s'", File, Line, Function, ErrorString) << std::endl;
        else
            std::cerr << ("OpenGL Error in %s at line %d calling function %s: '%d 0x%X'", File, Line, Function, Error, Error) << std::endl;
    }
}

inline void PrintShaderInfoLog(GLint const Shader)
{
    int InfoLogLength = 0;
    int CharsWritten = 0;

    glGetShaderiv(Shader, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0)
    {
        GLchar* InfoLog = new GLchar[InfoLogLength];
        glGetShaderInfoLog(Shader, InfoLogLength, &CharsWritten, InfoLog);
        std::cout << "Shader Info Log:" << std::endl << InfoLog << std::endl;
        delete[] InfoLog;
    }
}

#define GLCall(x) do { PrintOpenGLErrors(">>BEFORE<< "#x, __FILE__, __LINE__); (x); PrintOpenGLErrors(#x, __FILE__, __LINE__); } while (0)
#define GLResultCall(x) (x); PrintOpenGLErrors(#x, __FILE__, __LINE__)
#define CheckExistingErrors(x) PrintOpenGLErrors(">>BEFORE<< "#x, __FILE__, __LINE__)

#endif //TRABALHO1_GLHELPERS_H
