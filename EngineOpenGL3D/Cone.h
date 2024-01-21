#pragma once

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

class Cone {
public:
    Cone();

    void run();

private:
    Shader shaderProgram;
    VAO VAO1;
    VBO VBO1;
    EBO EBO1;

    const int numVertices = 360;
    GLfloat ConeVertices[360 * 6];

    void createConeVertices();
    void setupBuffers();
};
