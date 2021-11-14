#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Windows.h>

class Window {


private:

	GLFWwindow* window;

public:

	Window(int width, int height, const char* title = "", bool consoleMod = false) {

		HWND hWnd = GetConsoleWindow();

		if (consoleMod) {

			ShowWindow(hWnd, SW_HIDE);
		}
		else {

			ShowWindow(hWnd, SW_SHOW);
		}

		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		glfwMakeContextCurrent(window);


	}

	bool isOpen() {


		return !glfwWindowShouldClose(window);

	}

	GLFWwindow* getWindow() {

		return window;

	}

	void clear(float r, float g, float b, float a) {

		gladLoadGL();
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	~Window() {

		glfwDestroyWindow(window);

	}

};