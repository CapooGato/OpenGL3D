#include "Cubelmao.h"

/*
// Vertices coordinates
GLfloat vertices[] =
{
    // Pierwsza �ciana (prz�d)
    -1.0f, -1.0f, -1.0f,  // Wierzcho�ek 0
     1.0f, -1.0f, -1.0f,  // Wierzcho�ek 1
    -1.0f,  1.0f, -1.0f,  // Wierzcho�ek 2
     1.0f,  1.0f, -1.0f,  // Wierzcho�ek 3

              // Druga �ciana (ty�)
    -1.0f, -1.0f,  1.0f,  // Wierzcho�ek 4
     1.0f, -1.0f,  1.0f,  // Wierzcho�ek 5
    -1.0f,  1.0f,  1.0f,  // Wierzcho�ek 6
     1.0f,  1.0f,  1.0f,  // Wierzcho�ek 7

              // Trzecia �ciana (lewa)
    -1.0f, -1.0f, -1.0f,  // Wierzcho�ek 8
    -1.0f,  1.0f, -1.0f,  // Wierzcho�ek 9
    -1.0f, -1.0f,  1.0f,  // Wierzcho�ek 10
    -1.0f,  1.0f,  1.0f,  // Wierzcho�ek 11

              // Czwarta �ciana (prawa)
     1.0f, -1.0f, -1.0f,  // Wierzcho�ek 12
     1.0f,  1.0f, -1.0f,  // Wierzcho�ek 13
     1.0f, -1.0f,  1.0f,  // Wierzcho�ek 14
     1.0f,  1.0f,  1.0f,  // Wierzcho�ek 15

              // Pi�ta �ciana (dolna)
    -1.0f, -1.0f, -1.0f,  // Wierzcho�ek 16
     1.0f, -1.0f, -1.0f,  // Wierzcho�ek 17
    -1.0f, -1.0f,  1.0f,  // Wierzcho�ek 18
     1.0f, -1.0f,  1.0f,  // Wierzcho�ek 19

              // Sz�sta �ciana (g�rna)
    -1.0f,  1.0f, -1.0f,  // Wierzcho�ek 20
     1.0f,  1.0f, -1.0f,  // Wierzcho�ek 21
    -1.0f,  1.0f,  1.0f,  // Wierzcho�ek 22
     1.0f,  1.0f,  1.0f   // Wierzcho�ek 23
};

// Indices for vertices order
GLuint indices[] =
{
    0, 1, 2, 2, 1, 3,   // Pierwsza �ciana (prz�d)
    4, 5, 6, 6, 5, 7,   // Druga �ciana (ty�)
    8, 9, 10, 10, 9, 11, // Trzecia �ciana (lewa)
    12, 13, 14, 14, 13, 15, // Czwarta �ciana (prawa)
    16, 17, 18, 18, 17, 19, // Pi�ta �ciana (dolna)
    20, 21, 22, 22, 21, 23  // Sz�sta �ciana (g�rna)	
};
*/






 // Constructor 
Cube::Cube(){
    std::cout << "Cube created\n";

}

Cube::~Cube() {

    std::cout << "Cube destroyed\n";
}
