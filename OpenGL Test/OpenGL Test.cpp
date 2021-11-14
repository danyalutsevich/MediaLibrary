#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "EBO.h"
#include "VBO.h"
#include "Window.h"


GLfloat vertices[] = {

	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
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

	Window window(800,800,"TESTING",1);




	glfwMakeContextCurrent(window.getWindow());

	gladLoadGL();

	glViewport(0, 0, 800, 800);


	Shader shaderProgram("vertex.vert", "fragment.frag");



	VAO vao;
	vao.bind();

	VBO vbo(vertices, sizeof(vertices));
	vbo.bind();

	EBO ebo(indices, sizeof(indices));

	//vao.linkVBO(vbo, 0);

	vao.linkAttrib(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	vao.linkAttrib(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	vao.unbind();
	vbo.unbind();
	ebo.unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID,"scale");



	while (!glfwWindowShouldClose(window.getWindow())) {


		glClearColor(rand()%100/100.f, rand() % 100 / 100.f, rand() % 100 / 100.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.activate();
		glUniform1f(uniID, 1.-rand() % 200 / 100.f);
		vao.bind();

		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window.getWindow());


		glfwPollEvents();
	}


	vao.deactivate();
	vbo.deactivate();
	ebo.deactivate();
	shaderProgram.deactivate();

	
	glfwTerminate();


	return 0;
}

