#pragma once
#include <vector>
//#include "settings.h"
#include<GL\glut.h>

using namespace std;

const int ROWS = 9;
const int COLS = 16;
class Map
{


private:
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
    
public:
  

    void draw()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode (GL_MODELVIEW);
        glColor3f(.5, 0.4, 0.3);
        // draw squares in positions of the 1's

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (arr[i][j] == '1') 
                {    // 150, 36,150,36
                     glRectf(j, (ROWS - i) , ((j + 1)), ((ROWS - i-1)));
                   
                }
            }
        }
        //glMatrixMode (GL_PROJECTION);
        glutSwapBuffers();
        glFlush ();
    }
};

