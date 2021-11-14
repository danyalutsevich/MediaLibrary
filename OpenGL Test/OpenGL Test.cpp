#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "EBO.h"
#include "VBO.h"


GLfloat vertices[] = {

	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, 
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f 
};

GLuint indices[] = {
	0, 3, 5,
	3, 2, 4,
	5, 4, 1
};

int main() {


	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "TESTING", NULL, NULL);


	if (window == NULL) {

		std::cout << "Failed to create GLFW window\n";

		glfwTerminate();
		return -1;

	}

	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 800, 800);


	Shader shaderProgram("vertex.vert", "fragment.frag");



	VAO vao;
	vao.bind();

	VBO vbo(vertices, sizeof(vertices));
	vbo.bind();

	EBO ebo(indices, sizeof(indices));

	vao.linkVBO(vbo, 0);

	vao.unbind();
	vbo.unbind();
	ebo.unbind();


	while (!glfwWindowShouldClose(window)) {


		glClearColor(0.5, 0.5, 0.5, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.activate();
		vao.bind();

		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);


		glfwPollEvents();
	}


	vao.deactivate();
	vbo.deactivate();
	ebo.deactivate();
	shaderProgram.deactivate();

	glfwDestroyWindow(window);
	glfwTerminate();


	return 0;
}

