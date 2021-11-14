#pragma once

#include <glad/glad.h>

class VBO {

public:

	GLuint ID;

	VBO(GLfloat* vertices, GLsizeiptr size) {

		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	}

	void bind() {

		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	void unbind() {

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void deactivate() {

		glDeleteBuffers(1, &ID);
	}


};