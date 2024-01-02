#include "Cubelmao.h"

/*
// Vertices coordinates
GLfloat vertices[] =
{
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

// Indices for vertices order
GLuint indices[] =
{
    0, 1, 2, 2, 1, 3,   // Pierwsza œciana (przód)
    4, 5, 6, 6, 5, 7,   // Druga œciana (ty³)
    8, 9, 10, 10, 9, 11, // Trzecia œciana (lewa)
    12, 13, 14, 14, 13, 15, // Czwarta œciana (prawa)
    16, 17, 18, 18, 17, 19, // Pi¹ta œciana (dolna)
    20, 21, 22, 22, 21, 23  // Szósta œciana (górna)	
};
*/






 // Constructor 
Cube::Cube(){
    std::cout << "Cube created\n";

}

Cube::~Cube() {

    std::cout << "Cube destroyed\n";
}
