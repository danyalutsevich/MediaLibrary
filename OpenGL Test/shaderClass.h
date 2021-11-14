#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string getFileContents(const char* filename) {

	std::ifstream in(filename, std::ios::binary);
	if (in) {

		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		std::cout << contents << "\n";
		return contents;

	}
	throw(std::exception(filename));

}

class Shader {

public:
	GLuint ID;
	Shader(const char* vertexfile, const char* fragmentFile) {

		std::string vertexCode = getFileContents(vertexfile);
		std::string fragmentCode = getFileContents(fragmentFile);

		const char* vertexSorce = vertexCode.c_str();
		const char* fragmentSource = fragmentCode.c_str();

		std::cout << vertexSorce << "\n";
		std::cout << fragmentSource << "\n";

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSorce, NULL);
		glCompileShader(vertexShader);

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);

		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);


		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}

	void activate() {

		glUseProgram(ID);
	}

	void deactivate() {

		glDeleteProgram(ID);
	}

};


