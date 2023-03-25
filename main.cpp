#include<GL\glut.h>
#include <iostream>
using namespace std;


// draws the shape i want. currently square.
void draw ();

// define the boundaries of the viewport, and make it resizeable.
void reshape (int, int);

void background ();



int main (int argc, char** argv)
{
// #################### INITIALIZE GLUT LIBRARY. ###########################
	cout << "testingg";
	/* We use the '&' operator here because we want the glut function to change the actuall value of the argc parameter,
	it needs to have access to the original memory location of the argument,not just a copy of its value.  */
	glutInit (&argc, argv);

	// specifies the color mode and the buffer mode
	// single buffer used for still images
	// double buffer used to mkae animation
	//  why double? To avoid flickering caused by updating on the same buffer at real time .
	glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE);
//###################### END INITIALIZE GLUT LIBRARY. #######################


//###################### CREATE WINDOW. ######################################
	// specify windows size aka resolution.
	glutInitWindowSize (500, 500); \

	// specify the start position of drawing the screen.
	// which means move 10 point to the x direction, then 10 points in y direction then start drawing the screen.
		glutInitWindowPosition (10, 10);

		// creating window and giving it a name.
	glutCreateWindow ("Studying Cg");
//###################### END CREATE WINDOW. ######################################

//###################### CALL BACK FUNCTION. ######################################
	glutDisplayFunc (draw);
	glutReshapeFunc (reshape);

	background ();
	cout << "test";
//###################### END CALL BACK FUNCTION. ######################################

	// MAIN LOOP. 
	// infinite loop until a specified actions happens to stop the program.
	glutMainLoop ();
}

void reshape (int w, int h)
{
	// start drawing the viewport from the start (0,0), to the specified w,h.
	// is used to specify the size and location of the rendering window.
	glViewport (0, 0, w, h);

	// Specifies the matrix operation needed to draw the viewpor.
	// The default mode is MODELVIEW
	// Projection is used to manipulate the scene's viewport angle and orientation. ex:(FOV, aspect ration,type of projection, e
	// MOdELVIEW  is used to manipulate the object you are drawing.
	glMatrixMode (GL_PROJECTION);

	// after every change in a mtrix mode we must use this function.
	// so the GL senses the cnage and updates the view.
	glLoadIdentity ();

	gluOrtho2D (-10, 10, -10, 10);

	//return back to model viewa after editing our shape.
	glMatrixMode (GL_MODELVIEW);


}


void draw ()
{
	// Everytime you draw something you must clear what you drew before.
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity ();





	// glLineWidth (10);

	// marks the start and end of the item geetin drawn.
	// always draw vertices anticlock wise.
	// AKA, start the point from the left then to the right the upward then downward.
	glBegin (GL_QUADS);

	// specifies the shape color.
	glColor3f (0, 0, 0);

	glVertex2f (-5, -5);
	glVertex2f (5, -5);
	glVertex2f (5, 5);
	glVertex2f (-5, 5);
	glEnd ();

	// long story short,  make sure that output is diplayed on the screen.
	glFlush ();
}

void background ()
{

	glClearColor (.5, .8, .2, 1);
}
