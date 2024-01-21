#pragma once

#include<glad/glad.h>
#include "AbstractArrayObject.h"

class VBO : protected AbstractArrayObject
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(GLfloat* vertices, GLsizeiptr size);

	// Binds the VBO
	void Bind() const override;
	// Unbinds the VBO
	void Unbind() const override;
	// Deletes the VBO
	void Delete() const override;
};
