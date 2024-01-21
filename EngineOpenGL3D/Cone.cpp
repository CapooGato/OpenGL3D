// Cone.cpp

#include "Cone.h"
#include <iostream>
#include <fstream>

#define M_PI 3.14159

Cone::Cone() : shaderProgram("Cone.vert", "Cone.frag"), VAO1(), VBO1(nullptr, 0), EBO1(nullptr, 0) {
    createConeVertices();
    setupBuffers();
}


void Cone::run() {
    // Aktywacja shadera
    shaderProgram.Activate();

    // Rysowanie sto¿ka
    VAO1.Bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, numVertices);
    VAO1.Unbind();

    // Deaktywacja shadera
    glUseProgram(0);
}

void Cone::createConeVertices() {
    float radius = 0.5f;
    float height = 1.0f;

    // Podstawa sto¿ka
    for (int i = 0; i < numVertices; ++i) {
        float theta = static_cast<float>(i) / numVertices * (2 * M_PI);
        float x = radius * cos(theta);
        float z = radius * sin(theta);

        ConeVertices[i * 6] = x;
        ConeVertices[i * 6 + 1] = -height / 2.0f;
        ConeVertices[i * 6 + 2] = z;
        ConeVertices[i * 6 + 3] = 1.0f;
        ConeVertices[i * 6 + 4] = 0.0f;
        ConeVertices[i * 6 + 5] = 0.0f;
    }

    // Wierzcho³ek wierzcho³ka sto¿ka
    ConeVertices[numVertices * 6] = 0.0f;
    ConeVertices[numVertices * 6 + 1] = height / 2.0f;
    ConeVertices[numVertices * 6 + 2] = 0.0f;
    ConeVertices[numVertices * 6 + 3] = 1.0f;
    ConeVertices[numVertices * 6 + 4] = 0.0f;
    ConeVertices[numVertices * 6 + 5] = 0.0f;
}

void Cone::setupBuffers() {
    // W³aœciwa konfiguracja VAO, VBO, EBO
    VAO1.Bind();

    VBO1 = VBO(ConeVertices, sizeof(ConeVertices));
    EBO1 = EBO(nullptr, 0); // EBO nie jest potrzebne do rysowania w GL_TRIANGLE_FAN

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    VAO1.Unbind();
}
