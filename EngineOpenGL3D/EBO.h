#pragma once

#include<glad/glad.h>
#include "AbstractArrayObject.h"

class EBO : protected AbstractArrayObject
{
public:
	// ID reference of Elements Buffer Object
	GLuint ID;
	// Constructor that generates a Elements Buffer Object and links it to indices
	EBO(GLuint* indices, GLsizeiptr size);

	// Binds the EBO
	void Bind() const override;
	// Unbinds the EBO
	void Unbind() const override;
	// Deletes the EBO
	void Delete() const override;
};
