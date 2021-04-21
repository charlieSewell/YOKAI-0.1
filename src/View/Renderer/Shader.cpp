//
// Created by Charlie Sewell on 13/01/2021.
//

#include "Shader.hpp"

Shader::Shader(const char *vertexPath, const char *fragmentPath) 
{
    std::string vertexShaderSource;
    std::string fragmentShaderSource;
    try
    {
        std::stringstream vertexShaderSS;
        std::stringstream fragmentShaderSS;
        std::ifstream vertexShaderFile;
        std::ifstream fragmentShaderFile;
        vertexShaderFile.open(vertexPath);
        fragmentShaderFile.open(fragmentPath);

        vertexShaderSS << vertexShaderFile.rdbuf();
        fragmentShaderSS << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();
        vertexShaderSource = vertexShaderSS.str();
        fragmentShaderSource = fragmentShaderSS.str();
    }
    catch(std::ifstream::failure& e)
    {
        std::cout << "File failed to read" << e.what()<< std::endl;
    }

    const char* vertexShaderCode = vertexShaderSource.c_str();
    const char* fragmentShaderCode = fragmentShaderSource.c_str();
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
    glCompileShader(vertexShader);
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Vertex shader compilation failed\n" << infoLog << std::endl;
    }
    //create fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Fragment shader compilation failed\n" << infoLog << std::endl;
    }
    //create shader program
    shaderID = glCreateProgram();
    glAttachShader(shaderID, vertexShader);
    glAttachShader(shaderID, fragmentShader);
    glLinkProgram(shaderID);
    glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::useShader()
{
    glUseProgram(shaderID);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
}
void Shader::setMat4(const std::string &name, const glm::mat4 &mat)const 
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setVec3(const std::string &name, const glm::vec3 &vec) const 
{
    glUniform3fv(glGetUniformLocation(shaderID, name.c_str()), 1, &vec[0]);
}