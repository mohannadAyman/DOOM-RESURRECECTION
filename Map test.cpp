#include <iostream>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>

using namespace std;

const int ROWS = 50;
const int COLS = 50;
char arr[ROWS][COLS];

void init() {
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, COLS, 0.0, ROWS);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    // draw squares in positions of the 1's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == '1') {
                glRecti(j, ROWS - i - 1, j + 1, ROWS - i);
            }
        }
    }

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    srand(time(nullptr)); // initialize random seed

    // initialize array with '_' and make the first column, first row, last column, and last row 1's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                arr[i][j] = '1';
            }
            else {
                arr[i][j] = '_';
            }
        }
    }

    // randomly place '_' and '1' characters
    for (int k = 0; k < 1200; k++) { // 5 is the number of characters to randomly place
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (arr[row][col] == '1') { // if the randomly selected cell is already a '1', try again
            k--;
            continue;
        }
        char c = rand() % 2 == 0 ? '_' : '1'; // randomly choose between '_' and '1'
        arr[row][col] = c;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Grid with 1's and _'s");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
