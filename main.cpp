#include <iostream>
#include  <vector>
#include <stb/stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//#include "Map.h"
using namespace std;
const int ROWS = 9;
const int COLS = 16;
void draw()
{
    vector<vector<char>> arr =
    {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '1'},
        {'1', '-', '-', '1', '1', '1', '1', '-', '-', '-', '1', '1', '1', '-', '-', '1'},
        {'1', '-', '-', '-', '-', '-', '1', '-', '-', '-', '-', '-', '1', '-', '-', '1'},
        {'1', '-', '-', '-', '-', '-', '1', '-', '-', '-', '-', '-', '1', '-', '-', '1'},
        {'1', '-', '-', '1', '1', '1', '1', '-', '-', '-', '-', '-', '-', '-', '-', '1'},
        {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '1'},
        {'1', '-', '-', '1', '-', '-', '-', '-', '1', '-', '-', '-', '-', '-', '-', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    // Set up orthographic projection
    glOrtho (0, COLS, 0, ROWS, -1, 1);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();

    glColor3f (0.5, 0.4, 0.3);

    // Draw squares in positions of the '1's
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] == '1')
            {
                glRectf (j, (ROWS - i), ((j + 1)), ((ROWS - i - 1)));
            }
        }
    }
	glMatrixMode (GL_PROJECTION);
}





int main ()
{
	glfwInit ();

	// choosing the version 3.3
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);

	// There are 2 glfw packages. Here we are using modern package in.
	
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	GLFWmonitor*  monitor = glfwGetPrimaryMonitor ();
	GLFWwindow* window = glfwCreateWindow (1600, 900, "DOOM RESURRECTION", NULL, NULL);

	if (window == NULL)
	{
		cout << "error " << endl;
		glfwTerminate ();
		return -1;
	}
	
	// after creating the windows, you must tell glfw to show it on the screen.
	glfwMakeContextCurrent (window);
	
	// SPRITES
	int widthimg, heightimg, colorch;
	unsigned char* bytes = stbi_load ("C:/Users/user/Documents/GitHub/DOOM - RESURRECECTION/resources/sprites/weapon/shotgun/0.png", &widthimg, &heightimg, &colorch,0);

	GLuint texture;
	glGenTextures (1, &texture);
	glActiveTexture (GL_TEXTURE0);
	glBindTexture (GL_TEXTURE_2D, texture);

	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	//glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, widthimg, heightimg, colorch, 0,GL_RGBA, GL_UNSIGNED_BYTE, bytes);

	
	int width, height;
	glfwGetFramebufferSize (window, &width, &height);
	glViewport (0, 0, width, height);
	
	glfwSwapBuffers (window);

	while (!glfwWindowShouldClose (window))
	{

		draw ();
		glfwSwapBuffers (window);
		glfwPollEvents ();
	}

	glfwDestroyWindow (window);
	glfwTerminate ();
	return 0;
}

