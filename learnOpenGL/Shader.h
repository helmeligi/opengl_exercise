/*
 * Shader.h
 *
 *  Created on: Mar 13, 2017
 *      Author: hisham
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h> // Include glew to get all the required OpenGL headers

class Shader {
public:
  	// The program ID
	GLuint Program;
	// Constructor reads and builds the shader
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
  	// Use the program
  	void Use();
};

#endif /* SHADER_H_ */
