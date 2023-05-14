#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENATION
#include <stb/stb_image.h>

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
	
	gladLoadGL ();
	// SPRITES
	int widthimg, heightimg, colorch;
    

    GLuint textures[6]; // Assuming you have 6 images (0.png to 5.png)

// Load and generate textures for each image
    for (int i = 0; i <= 5; i++)
    {
        std::stringstream ss;
        ss << R"(C:\Users\user\Documents\GitHub\DOOM-RESURRECECTION\resources\sprites\weapon\shotgun\)" << i << ".png";
        std::string filePath = ss.str ();

        // Load the image
        int widthimg, heightimg, colorch;
        unsigned char* bytes = stbi_load (filePath.c_str (), &widthimg, &heightimg, &colorch, 0);

        // Generate a new texture
        glGenTextures (1, &textures[i]);
        glBindTexture (GL_TEXTURE_2D, textures[i]);

        // Set texture parameters
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // Upload image data to the texture
        glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, widthimg, heightimg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
        glGenerateMipmap (GL_TEXTURE_2D);

        // Free the image data
        stbi_image_free (bytes);
    }

    // ...

    // Animation loop
    while (!glfwWindowShouldClose (window))
    {
        glClear (GL_COLOR_BUFFER_BIT);

        // Calculate the index of the current frame
        int frameIndex = static_cast<int>(glfwGetTime ()) % 6; // Assuming 6 images (0.png to 5.png)

        // Render the current frame
        glEnable (GL_TEXTURE_2D);
        glBindTexture (GL_TEXTURE_2D, textures[frameIndex]);
        glBegin (GL_QUADS);
        glTexCoord2f (0, 0); glVertex2f (-1, 1);
        glTexCoord2f (1, 0); glVertex2f (1, 1);
        glTexCoord2f (1, 1); glVertex2f (1, -1);
        glTexCoord2f (0, 1); glVertex2f (-1, -1);
        glEnd ();
        glDisable (GL_TEXTURE_2D);

        glfwSwapBuffers (window);
        glfwPollEvents ();
    }

	glfwDestroyWindow (window);
	glfwTerminate ();
	return 0;
}

