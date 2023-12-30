#include "CameraControl.h"
#include <glm/gtc/matrix_transform.hpp>

CameraControls::CameraControls(GLFWwindow* window, glm::vec3 initialPosition)
    : position(initialPosition), horizontalAngle(3.14f), verticalAngle(0.0f),
    initialFoV(45.0f), speed(3.0f), mouseSpeed(0.005f), window(window), lastTime(glfwGetTime()) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void CameraControls::update() {

    glm::vec3 right(
        sin(horizontalAngle - 3.14f / 2.0f),
        0,
        cos(horizontalAngle - 3.14f / 2.0f)
    );

    up = glm::cross(right, direction);

    computeMatricesFromInputs();
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);
    lastTime = currentTime;

    // Move forward
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        position += direction * deltaTime * speed;
    }
    // Move backward
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        position -= direction * deltaTime * speed;
    }
    // Strafe right
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        position += right * deltaTime * speed;
    }
    // Strafe left
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        position -= right * deltaTime * speed;
    }

    // Zoom using mouse wheel
   // FoV = initialFoV - 5 * glfwGetMouseWheel();
}

glm::mat4 CameraControls::getViewMatrix() {
    return glm::lookAt(position, position + direction, up);
}

glm::mat4 CameraControls::getProjectionMatrix() {
    return glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
}

void CameraControls::computeMatricesFromInputs() {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    glfwSetCursorPos(window, 1024 / 2, 768 / 2);

    horizontalAngle += mouseSpeed * float(1024 / 2 - xpos);
    verticalAngle += mouseSpeed * float(768 / 2 - ypos);

    direction = glm::vec3(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );

   
}
