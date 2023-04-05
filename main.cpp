#include <iostream>
#include "Settings.h"
#include <Windows.h>

#include "Map.h"
#include<GL\glut.h>


void reshape (int, int);
void background ();

class Game
{
public:

	static Map map;

	Game ()
	{
		
		float delta_time = 1;
		glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE);
		glutInitWindowSize (WIDTH, HEIGHT);
		glutInitWindowPosition (0, 0);
		glutCreateWindow ("Studying Cg");
		glutDisplayFunc (new_game);
		glutReshapeFunc (reshape);
		background ();

		
	};

	 static void new_game ()
	{
		
		map.draw();
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
Map Game::map;
int main (int argc, char** argv)
{

	glutInit (&argc, argv);
	Game game;

	game.Run ();
}


void reshape (int w, int h)
{	
	float ratio;
	if (h == 0)
	{
		h = 1;
	}
	ratio = (float)w / h;

	glViewport (0, 0, w, h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//if (w >= h)
	//{
		gluOrtho2D (0, 16, 0, 9);
		cout << "width is here: " << h;
	//}
	//else
	//{
	//	gluOrtho2D (-10, 10, -10/ratio, 10/ratio);
	//}
	
	
}

void background ()
{
	glClearColor (0, 0, 0, 1);
}
