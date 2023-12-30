#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <math.h>

class CameraControls {
public:
    CameraControls(GLFWwindow* window, glm::vec3 initialPosition = glm::vec3(0, 0, 5));

    void update();

    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();

private:
    glm::vec3 position;
    float horizontalAngle;
    float verticalAngle;
    float initialFoV;

    float speed;
    float mouseSpeed;

    GLFWwindow* window;
    double lastTime;

    glm::vec3 direction;
    glm::vec3 up;
    float FoV;

    void computeMatricesFromInputs();
};
