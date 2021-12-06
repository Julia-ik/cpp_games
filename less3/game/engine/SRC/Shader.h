//
// Created by lilu on 30.11.2021.
//

#ifndef GAME_SHADER_H
#define GAME_SHADER_H
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/detail/type_vec2.hpp>

class Shader
{
public:
Shader();

    Shader(GLuint programID);

    Shader &Use();
GLuint uScreenSize =0;
GLuint programID;

    void SetFloat (const char *name, float value, bool useShader = false);
    void SetInteger (const char *name, int value, bool useShader = false);
    void SetVector2f (const char *name, float x, float y, bool useShader = false);
    void SetVector2f (const char *name, const glm::vec2 &value, bool useShader = false);
    void SetVector3f (const char *name, float x, float y, float z, bool useShader = false);
    void SetVector3f (const char *name, const glm::vec3 &value, bool useShader = false);
    void SetVector4f (const char *name, float x, float y, float z, float w, bool useShader = false);
    void SetVector4f (const char *name, const glm::vec4 &value, bool useShader = false);
    void SetMatrix4 (const char *name, const glm::mat4 &matrix, bool useShader = false);
};


#endif //GAME_SHADER_H
