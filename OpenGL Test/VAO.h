#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO {

public:

	GLuint ID;
	VAO() {

		glGenVertexArrays(1, &ID);
	}

	void linkVBO(VBO VBO, GLuint layout) {

		VBO.bind();
		glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(layout);
		VBO.unbind();
	}

	void bind() {

		glBindVertexArray(ID);
	}

	void unbind() {

		glBindVertexArray(0);
	}

	void deactivate() {

		glDeleteVertexArrays(1, &ID);
	}

};
