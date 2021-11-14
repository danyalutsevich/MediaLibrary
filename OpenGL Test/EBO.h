#pragma once
#pragma once

#include <glad/glad.h>

class EBO {

public:

	GLuint ID;

	EBO(GLuint* indices, GLsizeiptr size) {

		glGenBuffers(1, &ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

	}

	void bind() {

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}

	void unbind() {

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void deactivate() {

		glDeleteBuffers(1, &ID);
	}


};