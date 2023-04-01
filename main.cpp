#include <iostream>
#include "Settings.h"
#include <Windows.h>
#include<GL\glut.h>


void draw ();
void reshape (int, int);
void background ();

class Game
{
public:

	Game ()
	{
		float delta_time = 1;
		glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE);
		glutInitWindowSize (WIDTH, HEIGHT);
		glutInitWindowPosition (10, 10);
		glutCreateWindow ("Studying Cg");
		glutDisplayFunc (draw);
		glutReshapeFunc (reshape);
		background ();

		
	};

	void new_game ()
	{
	};

	void Update ()
	{
		
	};

	void Draw ()
	{
		glClear (GL_COLOR_BUFFER_BIT);
		glLoadIdentity ();
		glFlush ();
	};

	void Check_Events ()
	{
	};

	void Run ()
	{

		glutMainLoop ();
	};

};

int main (int argc, char** argv)
{

	glutInit (&argc, argv);
	Game game;

	game.Run ();
}


void draw ()
{
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity ();
	glFlush ();
}

void reshape (int w, int h)
{	
	glViewport (0, 0, w, h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (-10, 10, -10, 10);
	glMatrixMode (GL_MODELVIEW);
}

void background ()
{
	glClearColor (0, 0, 0, 1);
}
