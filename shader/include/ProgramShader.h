#ifndef ProgramShader_SHADER_H
#define ProgramShader_SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "ShaderException.h"

using namespace std;
using namespace glm;


class ProgramShader
{
    public:
        ProgramShader();
        virtual ~ProgramShader();

        void startup();
        void use() throw();
        void shutdown();

        void setUniform(const string& name, GLfloat val);
        void setUniform(const string& name, GLint val);
        void setUniform(const string& name, GLboolean val);
        void setUniform(const string& name, GLfloat x, GLfloat y, GLfloat z);
        void setUniform(const string& name, const vec2& vec);
        void setUniform(const string& name, const vec3& vec);
        void setUniform(const string& name, const vec4& vec);
        void setUniform(const string& name, const mat3& matrix);
        void setUniform(const string& name, const mat4& matrix);

    private:
        string readFile(string path);
        void addShader(const string& file, GLenum type);
        void removeShader(GLenum type, GLuint shader);
        void removeProgram();
        GLuint compileShader(const string& source, GLenum type) throw();
        void link() throw();
        void addUniform(const string& uniform);
        void removeUniform(const string& uniform);

    private:
        GLuint program;
        map<GLenum, GLuint> shaders;
        map<string, GLuint> uniforms;
};

#endif // ProgramShader_H
