#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Szescian {
public:
    Szescian() {
        initOpenGL();
        initGeometry();
    }

    ~Szescian() {
        cleanUp();
    }

    void run() {
        while (!glfwWindowShouldClose(window)) {
            render();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    GLFWwindow* window;
private:
    GLuint vertexArrayID;
    GLuint vertexBuffer;
    GLuint programID;
    GLuint matrixID;
    GLuint indexBuffer;

    float angle;

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

        static const GLuint g_element_buffer_data[] = {
            0, 1, 2, 2, 1, 3,   // Pierwsza œciana (przód)
            4, 5, 6, 6, 5, 7,   // Druga œciana (ty³)
            8, 9, 10, 10, 9, 11, // Trzecia œciana (lewa)
            12, 13, 14, 14, 13, 15, // Czwarta œciana (prawa)
            16, 17, 18, 18, 17, 19, // Pi¹ta œciana (dolna)
            20, 21, 22, 22, 21, 23  // Szósta œciana (górna)
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
        const char* vertexShaderCode =
            "#version 450\n"
            "layout(location = 0) in vec3 vertexPosition_modelspace;"
            "uniform mat4 MVP;"
            "void main(){"
            "   gl_Position =  MVP * vec4(vertexPosition_modelspace,1);"
            "}";

        const char* fragmentShaderCode =
            "#version 450\n"
            "out vec4 color;"
            "void main(){"
            "   color = vec4(0.0, 0.0, 1.0, 1.0);"
            "}";

        GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShaderID, 1, &vertexShaderCode, NULL);
        glCompileShader(vertexShaderID);

        GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShaderID, 1, &fragmentShaderCode, NULL);
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

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        // GL_TRIANGLES dla szeœcianu (12 trójk¹tów)
        glDisableVertexAttribArray(0);
    }


    void computeMatricesFromInputs() {
        angle += 0.01f;

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
        return glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    void cleanUp() {
        glDeleteBuffers(1, &vertexBuffer);
        glDeleteVertexArrays(1, &vertexArrayID);
        glDeleteProgram(programID);

        glfwTerminate();
    }
};

