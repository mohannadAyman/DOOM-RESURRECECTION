#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

int main ()
{
	glfwInit ();

	// choosing the version 3.3
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);

	// There are 2 glfw packages. Here we are using modern package in.
	
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWmonitor*  monitor = glfwGetPrimaryMonitor ();
	GLFWwindow* window = glfwCreateWindow (800, 800, "DOOM RESURRECTION", NULL, NULL);

	if (window == NULL)
	{
		cout << "error " << endl;
		glfwTerminate ();
		return -1;
	}

	// after creating the windows, you must tell glfw to show it on the screen.
	glfwMakeContextCurrent (window);

	gladLoadGL (); 

	glViewport (0, 0, 800, 800);
	glClearColor (0.07f, 0.13f, 0.17f, 1.0f);
	glClear (GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers (window);

	while (!glfwWindowShouldClose (window))
	{
		glfwPollEvents ();
	}

	glfwDestroyWindow (window);
	glfwTerminate ();
	return 0;
}