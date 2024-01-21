#pragma once


class AbstractArrayObject {

protected:
    virtual ~AbstractArrayObject() {}

    // Binds the buffer object
    virtual void Bind() const = 0;

    // Unbinds the buffer object
    virtual void Unbind() const = 0;

    // Deletes the buffer object
    virtual void Delete() const = 0;



};