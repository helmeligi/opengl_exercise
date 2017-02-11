/*
 * Test1.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: hisham
 */
#include <stdlib.h>
#include <iostream>

using namespace std;
/**
 * GLEW: GL Extension Wrangler to manage cumbersome mapping.
 * Use GLEW via their static library; large executable.
 *
 * You need to link with:
 * lGLEW -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi.
 *
 * Be sure to include GLEW before GLFW. The include file for GLEW contains the
 * correct OpenGL header includes (like GL/gl.h) so including GLEW before other
 * header files that require OpenGL does the trick.
 */
#define GLEW_STATIC
#include <GL/glew.h>

/**
 * This concludes the setup and configuration of GLFW.
 * GLFW --> openGL Framework */
#include <GLFW/glfw3.h>

static GLFWwindow* window;

/**
 * Init sequence:
 * 	1-Instantiate the GLFW window.
 *
 * 	2-Specify GLFW version e.g 3.3 is the OpenGL version we want to use.
 * 	  This way GLFW can make the proper arrangements when creating the OpenGL
 * 	 context. Also This ensures that when a user does not have the proper OpenGL
 * 	 version GLFW fails to run
 *
 *  3-Tell GLFW we want to explicitly use the core-profile.
 *     Telling GLFW explicitly that we want to use the core-profile will result
 *     in invalid operation errors whenever we call one of OpenGL's legacy
 *     functions, which is a nice reminder when we accidentally use old
 *     functionality where we'd rather stay away from.
 *
 *      To find the OpenGL version on your machine either call glxinfo on Linux.
 */
void initGL() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

/**
 *  Tell OpenGL the size of the rendering window so OpenGL knows how we want to
 *  display the data and coordinates with respect to the window.
 *
 * The first two parameters of glViewport set the location of the lower
 * left corner of the window.
 * The third and fourth parameter set the width and height of the rendering
 * window in pixels, which we retrieve here from GLFW itself.
 * Instead of setting a width and height of 800 and 600 respectively we take
 * the viewport dimensions from GLFW such that it also works on high DPI
 * screens (like Apple's retina displays).
 *
 * Behind the scenes OpenGL uses the data specified via glViewport to
 * transform the 2D coordinates it processed to coordinates on your screen.
 * For example, a processed point of location (-0.5,0.5) would (as its
 * final transformation) be mapped to (200,450) in screen coordinates.
 *
 * Note that processed coordinates in OpenGL are between -1 and 1 so we
 * effectively map from the range (-1 to 1) to (0, 800) and (0, 600).
 */
void initViewPort() {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);
}

/**
 * Create a window object:
 *  create a window object. This window object holds all the windowing data
 *  and is used quite frequently by GLFW's other functions.
 */
int createWindowObject() {

	window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	return 0;
}

/**
 * Init GLEW:
 *  set the glewExperimental variable to GL_TRUE before initializing GLEW.
 *  Setting glewExperimental to true ensures GLEW uses more modern
 *  techniques for managing OpenGL functionality. Leaving it to its default
 *  value of GL_FALSE might give issues when using the core profile of
 *  OpenGL.
 */
int initGLEW() {

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	return 0;
}

void render(){
	/**
	 * Note that we also set a color via glClearColor to clear the screen with.
	 * Whenever we call glClear and clear the color buffer, the entire
	 * colorbuffer will be filled with the color as configured by glClearColor.
	 * This will result in a dark green-blueish color.
	 */
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	/**
	 * We can clear the screen's color buffer using the glClear function where
	 * we pass in buffer bits to specify which buffer we would like to clear.
	 * The possible bits we can set are GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT
	 * and GL_STENCIL_BUFFER_BIT. Right now we only care about the color values
	 * so we only clear the color buffer.
	 */
	glClear(GL_COLOR_BUFFER_BIT);
}

void run() {

	while (!glfwWindowShouldClose(window)) {

		/**
		 * The glfwPollEvents function checks if any events are triggered
		 *  (like keyboard input or mouse movement events) and calls the
		 *  corresponding functions (which we can set via callback methods).
		 *  We usually call eventprocessing functions at the start of a loop
		 *  iteration.
		 *  */
		glfwPollEvents();

		/**
		 * We want to place all the rendering commands in the game loop, since
		 * we want to execute all the rendering commands each iteration of the
		 * loop
		 */
		// Rendering commands here
		render();

		/**
		 * The glfwSwapBuffers will swap the color buffer (a large buffer that
		 * contains color values for each pixel in GLFW's window) that has
		 * been used to draw in during this iteration and show it as output to
		 * the screen.
		 *
		 * Double buffer: When an application draws in a single buffer the
		 * resulting image might display flickering issues.
		 * This is because the resulting output image is not drawn in an i
		 * nstant, but drawn pixel by pixel and usually from left to right and
		 * top to bottom. Because these images are not displayed at an instant
		 * to the user, but rather via a step by step generation the result may
		 *  contain quite a few artifacts.
		 *  To circumvent these issues, windowing applications apply a double
		 *  buffer for rendering. The front buffer contains the final output
		 *  image that is shown at the screen, while all the rendering commands
		 *  draw to the back buffer. As soon as all the rendering commands are
		 *  finished we swap the back buffer to the front buffer so the image
		 *  is instantly displayed to the user, removing all the aforementioned
		 *  artifacts.
		 */
		glfwSwapBuffers(window);
	}
}

/**
 * As soon as we exit the game loop we would like to properly clean/delete all
 * resources that were allocated. We can do this via the glfwTerminate function
 * that we call at the end of the main function.
 */
void cleanResources() {
	glfwTerminate();
}

/**
 * KeyCallback function, which should be called whenever the user interacts with
 * the keyboard.
 *
 * The key input function takes a GLFWwindow as its first argument, an integer
 * that specifies the key pressed, an action that specifies if the key is
 * pressed or released and an integer representing some bit flags to tell you
 * if shift, control, alt or super keys have been pressed. Whenever a user
 * pressed a key, GLFW calls this function and fills in the proper arguments
 * for you to process.
 */
void key_callback(GLFWwindow* window, int key, int scancode, int action,
		int mode) {
	// When a user presses the escape key, we set the WindowShouldClose property
	//to true,
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int test1() {
	int error = 0;

	initGL();
	error |= createWindowObject();
	error |= initGLEW();
	initViewPort();
	// register the set key call back with the proper callback via GLFW.
	glfwSetKeyCallback(window, key_callback);
	run();

	cleanResources();

	return 0;
}

