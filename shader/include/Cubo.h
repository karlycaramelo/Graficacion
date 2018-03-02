#ifndef CUBO_H
#define CUBO_H

#include <iostream>
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <GL/glew.h>

using namespace std;
using namespace glm;

class Cubo
{
    public:
        Cubo();
        virtual ~Cubo();

        void startup();
        void shutdown();
        void draw();

    private:
        GLuint vao;
        GLuint vbo;
        GLuint cbo;

        vector<vec3> vertex;
        vector<vec3> colors;

        void init();
        void create();
        void bindData();
};

#endif // CUBO_H
