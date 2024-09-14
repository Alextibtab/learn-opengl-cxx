#pragma once

#include "gtc/type_ptr.hpp"
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
  void m_checkCompileErrors(unsigned int shader, std::string type) const;

public:
  unsigned int ID;

  Shader(const char *vertexPath, const char *fragmentPath);
  void use() const;

  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
  void setVec2f(const std::string &name, float x, float y) const;
  void setVec3f(const std::string &name, float x, float y, float z) const;
  void setVec4f(const std::string &name, float x, float y, float z,
                float w) const;
  void setMat4f(const std::string &name, glm::mat4 a) const;
};
