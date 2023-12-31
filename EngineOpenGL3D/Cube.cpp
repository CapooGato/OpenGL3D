#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

static const GLuint g_element_buffer_data[] = {
    0, 1, 2, 2, 1, 3,   // Pierwsza œciana (przód)
    4, 5, 6, 6, 5, 7,   // Druga œciana (ty³)
    8, 9, 10, 10, 9, 11, // Trzecia œciana (lewa)
    12, 13, 14, 14, 13, 15, // Czwarta œciana (prawa)
    16, 17, 18, 18, 17, 19, // Pi¹ta œciana (dolna)
    20, 21, 22, 22, 21, 23  // Szósta œciana (górna)
};

static std::string readShaderCode(const std::string& filePath) {
    std::ifstream fileStream(filePath.c_str(), std::ios::in);
    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}

class Szescian {
private:
    float rotationSpeedX;
    float rotationSpeedZ;

public:
    GLFWwindow* window;
    GLuint vertexArrayID;
    GLuint vertexBuffer;
    GLuint programID;
    GLuint matrixID;
    GLuint indexBuffer;
    float angle;
    float rotationSpeed;
    float rotationSpeedMultiplier;
    int rotationDirection;
    float scrollSpeed;

    // Funkcja zwrotna do obs³ugi zdarzeñ myszy
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        Szescian* szescian = static_cast<Szescian*>(glfwGetWindowUserPointer(window));

        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            // Po lewym klikniêciu myszy zwiêksz wspó³czynnik prêdkoœci obrotu
            szescian->rotationSpeedMultiplier *= 1.5f;
        }
        else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
            // Po prawym klikniêciu myszy zmniejsz wspó³czynnik prêdkoœci obrotu
            szescian->rotationSpeedMultiplier *= -1.0f;
        }
    }

    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
        Szescian* szescian = static_cast<Szescian*>(glfwGetWindowUserPointer(window));

        if (yoffset <= 0) {
            // Przewiniêcie w dó³ myszy, zmniejsz prêdkoœæ obrotu
            szescian->decreaseRotationSpeed();
        }
    }

    void decreaseRotationSpeed() {
        rotationSpeed *= 0.5f;
        if (rotationSpeed < 0.04f) {
            rotationSpeed = 0.05f; // Ustaw minimaln¹ wartoœæ prêdkoœci
        }
    }

    void handleKeyPress(int key) {
        switch (key) {
        case GLFW_KEY_W:
            // Obracaj siê wzglêdem osi x dodatnio
            rotationSpeedX = glm::radians(1.0f);
            break;
        case GLFW_KEY_S:
            // Obracaj siê wzglêdem osi x ujemnie
            rotationSpeedX = glm::radians(-1.0f);
            break;
        case GLFW_KEY_A:
            // Obracaj siê wzglêdem osi z ujemnie
            rotationSpeedZ = glm::radians(-1.0f);
            break;
        case GLFW_KEY_D:
            // Obracaj siê wzglêdem osi z dodatnio
            rotationSpeedZ = glm::radians(1.0f);
            break;
        default:
            // Inny klawisz - nie rób nic
            break;
        }
    }

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        Szescian* szescian = static_cast<Szescian*>(glfwGetWindowUserPointer(window));

        if (action == GLFW_PRESS || action == GLFW_REPEAT) {
            szescian->handleKeyPress(key);
        }
    }

public:
    Szescian() : rotationSpeed(0.1f), rotationSpeedMultiplier(1.0f), rotationDirection(1), scrollSpeed(0.1f), rotationSpeedX(0.0f), rotationSpeedZ(0.0f) {
        initOpenGL();
        initGeometry();
        angle = 1;
    }

    ~Szescian() {
        cleanUp();
    }

    void run() {
        glfwSetWindowUserPointer(window, this);

        // Ustaw funkcjê zwrotn¹ do obs³ugi zdarzeñ myszy
        glfwSetMouseButtonCallback(window, mouseButtonCallback);
        glfwSetScrollCallback(window, Szescian::scrollCallback);
        glfwSetKeyCallback(window, keyCallback);

        while (!glfwWindowShouldClose(window)) {
            handleKeyboardInput();
            render();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    void handleKeyboardInput() {
        // Obs³uga klawiszy WSAD
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            rotationSpeedX = glm::radians(30.0f);
        }
        else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            rotationSpeedX = glm::radians(-30.0f);
        }
        else {
            rotationSpeedX = 0.0f;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            rotationSpeedZ = glm::radians(-30.0f);
        }
        else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            rotationSpeedZ = glm::radians(30.0f);
        }
        else {
            rotationSpeedZ = 0.0f;
        }
    }

private:
    void initOpenGL() {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

        window = glfwCreateWindow(800, 600, "Obracaj¹cy siê szeœcian", NULL, NULL);
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    void initGeometry() {
        static const GLfloat g_vertex_buffer_data[] = {
            // Pierwsza œciana (przód)
            -1.0f, -1.0f, -1.0f,  // Wierzcho³ek 0
            1.0f, -1.0f, -1.0f,  // Wierzcho³ek 1
            -1.0f,  1.0f, -1.0f,  // Wierzcho³ek 2
            1.0f,  1.0f, -1.0f,  // Wierzcho³ek 3

            // Druga œciana (ty³)
            -1.0f, -1.0f,  1.0f,  // Wierzcho³ek 4
            1.0f, -1.0f,  1.0f,  // Wierzcho³ek 5
            -1.0f,  1.0f,  1.0f,  // Wierzcho³ek 6
            1.0f,  1.0f,  1.0f,  // Wierzcho³ek 7

            // Trzecia œciana (lewa)
            -1.0f, -1.0f, -1.0f,  // Wierzcho³ek 8
            -1.0f,  1.0f, -1.0f,  // Wierzcho³ek 9
            -1.0f, -1.0f,  1.0f,  // Wierzcho³ek 10
            -1.0f,  1.0f,  1.0f,  // Wierzcho³ek 11

            // Czwarta œciana (prawa)
            1.0f, -1.0f, -1.0f,  // Wierzcho³ek 12
            1.0f,  1.0f, -1.0f,  // Wierzcho³ek 13
            1.0f, -1.0f,  1.0f,  // Wierzcho³ek 14
            1.0f,  1.0f,  1.0f,  // Wierzcho³ek 15

            // Pi¹ta œciana (dolna)
            -1.0f, -1.0f, -1.0f,  // Wierzcho³ek 16
            1.0f, -1.0f, -1.0f,  // Wierzcho³ek 17
            -1.0f, -1.0f,  1.0f,  // Wierzcho³ek 18
            1.0f, -1.0f,  1.0f,  // Wierzcho³ek 19

            // Szósta œciana (górna)
            -1.0f,  1.0f, -1.0f,  // Wierzcho³ek 20
            1.0f,  1.0f, -1.0f,  // Wierzcho³ek 21
            -1.0f,  1.0f,  1.0f,  // Wierzcho³ek 22
            1.0f,  1.0f,  1.0f   // Wierzcho³ek 23
        };

        glGenVertexArrays(1, &vertexArrayID);
        glBindVertexArray(vertexArrayID);

        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        glGenBuffers(1, &indexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_element_buffer_data), g_element_buffer_data, GL_STATIC_DRAW);

        programID = loadShaders();
        matrixID = glGetUniformLocation(programID, "MVP");
    }

    GLuint loadShaders() {
        std::string vertexShaderCode = readShaderCode("vertexShader.glsl");
        std::string fragmentShaderCode = readShaderCode("fragmentShader.glsl");

        const char* vertexShaderSource = vertexShaderCode.c_str();
        const char* fragmentShaderSource = fragmentShaderCode.c_str();

        GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShaderID);

        GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShaderID);

        GLuint programID = glCreateProgram();
        glAttachShader(programID, vertexShaderID);
        glAttachShader(programID, fragmentShaderID);
        glLinkProgram(programID);

        glDetachShader(programID, vertexShaderID);
        glDetachShader(programID, fragmentShaderID);

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        return programID;
    }

    void render() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);

        computeMatricesFromInputs();
        glm::mat4 MVP = getProjectionMatrix() * getViewMatrix() * getModelMatrix();
        glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

        // Przekazuj kolor do shadera
        GLint colorUniform = glGetUniformLocation(programID, "VertexColor");
        glUniform4f(colorUniform, 1.0f, 0.0f, 0.0f, 1.0f);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
    }

    void computeMatricesFromInputs() {
        angle += rotationSpeed * rotationSpeedMultiplier;

        if (angle > 360.0f) {
            angle -= 360.0f;
        }
    }

    glm::mat4 getViewMatrix() {
        return glm::lookAt(
            glm::vec3(4, 3, 3),
            glm::vec3(0, 0, 0),
            glm::vec3(0, 1, 0)
        );
    }

    glm::mat4 getProjectionMatrix() {
        int windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        return glm::perspective(
            glm::radians(45.0f),
            float(windowWidth) / float(windowHeight),
            0.1f,
            100.0f
        );
    }

    glm::mat4 getModelMatrix() {
        return glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f))
            * glm::rotate(glm::mat4(1.0f), rotationSpeedX, glm::vec3(1.0f, 0.0f, 0.0f))
            * glm::rotate(glm::mat4(1.0f), rotationSpeedZ, glm::vec3(0.0f, 0.0f, 1.0f));
    }


    void cleanUp() {
        glDeleteBuffers(1, &vertexBuffer);
        glDeleteVertexArrays(1, &vertexArrayID);
        glDeleteProgram(programID);

        glfwTerminate();
    }
};

